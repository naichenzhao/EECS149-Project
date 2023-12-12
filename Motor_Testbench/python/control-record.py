#  Record USB Force/torque sensor data from USB to file
# July 2022, R.S. Fearing

# import msvcrt, sys
import numpy as np
import serial
import time
from time import sleep
import csv
import sys
import threading
from queue import Queue
from queue import LifoQueue
sendQ = Queue()
stateQ = LifoQueue()  # keeping track of remote state
# always use newest data
start_time = time.time()

from serial.tools import list_ports
# list_ports.comports()  # Outputs list of available serial ports
print('ports being used:')
print([port.device for port in serial.tools.list_ports.comports()])

#### CONSTANTS ###########
data_file_name = '../Data/data.txt'
telemetry = False
numSamples = 20 # 1 kHz sampling in pid loop = 3 sec
INTERVAL = 0.1  # update rate for state information


rcvStop = threading.Event()
rcvStop.clear()
sendStop = threading.Event()
sendStop.clear()
controlStop = threading.Event()
controlStop.clear()

ser = serial.Serial('COM3')
ser.baudrate=230400

# readline documentation https://docs.python.org/3/library/io.html#io.IOBase.readline
#line = ser.readline()   # discard possible partial line
#line = ser.readline()   # read one \n terminated line
#print("Read line =%s" % (line))

# =============================================================================
# reader = csv.reader(ser)
# for row in reader:
#    print(row)
# =============================================================================


class StateStruct():
    def __init__(self):
        self.time = 0.0
        self.hx711 = 0  # load cell
        self.qdec3 = 0  # quad decoder using timer 3
        self.qdec5 = 0  # quadrature decoder using timer 5
        self.adc8 = 0   # 12 bit A/D channels 8 to 15
        self.adc9 = 0
        self.adc10 = 0
        self.adc11 = 0
        self.adc12 = 0
        self.adc13 = 0
        self.adc14 = 0
        self.adc15 = 0 


# 
def processLine(textLine,index):
    newState = StateStruct()    
    #  "t=","hx711","qdec3","qdec4", "adc8","adc9","adc10", "adc11","adc12","adc13","adc14","adc15"
    data = textLine.split(',')  # split on comma
   # split first element on space delimiter to find #, which indicates a comment
    firstChar = data[0].split()
    if (firstChar[0] == '#') or (firstChar[0] == '***'):
 #           print(textLine)
             # check here for # STM32READY before enabling control_loop
            if(firstChar[1] == 'STM32READY'):  
                controlStop.clear()   # only start control loop if get STM32READY message
    else:
        # print(textLine)
        temp=np.zeros(np.size(data))
        for i in range(0,np.size(data)):
            temp[i] = float(data[i])
        
        newState.time = temp[0]
        newState.hx711 = temp[1]  
        newState.qdec3 = temp[2]  
        newState.qdec5 = temp[3]  
        newState.adc8 = temp[4]   
        newState.adc9 = temp[5]
        newState.adc10 = temp[6]
        newState.adc11 = temp[7]
        newState.adc12 = temp[8]
        newState.adc13 = temp[9]
        newState.adc14 = temp[10]
        newState.adc15 = temp[11] 
        
        stateQ.put(newState)
        
  #      if (index %100) == 0:
  #          print(index, end=',')




# thread receive state message from USB (STM32)
def rcvstate():
    print('Started rcvstate thread')
    writeFileHeader(data_file_name)
    fileout = open(data_file_name,'a') # append data to file
    if ser.isOpen():
        print("Serial open. Using port %s and baudrate %s" % (ser.name, ser.baudrate))
    else:
        print('serial open failed. Exiting.')
        exit()
   
    ser.reset_input_buffer() # get rid of accumulated inputs
    ser.flush()  # get rid of any extra outputs
    line = ser.readline()  # throw out first line read which is *** Booting Zephyr OS ***
    index = 0
    while not rcvStop.is_set():
        line = ser.readline()
 #       print("raw line = %s" %(line))
        line = line.decode('ascii')   # read one \n terminated line, convert to string
        line = line.replace("\n","")  # replace extra line feed (leave \r in place)
 #       print('rcv index:%d. StateQ size %d\t%s' %(index,stateQ.qsize(),line))
        fileout.write(str(line))
        processLine(line, index)  # convert text to state values, and place in stateQ
#        sleep(INTERVAL)   #don't delay, otherwise serial will be out of sync with control thread
        index +=1
        time.sleep(0.001)  # give up thread for other threads to run
    print("rcvstate: Closing file")
    fileout.close()
    print("rcvstate: Closing serial in 2 seconds")
    time.sleep(2)
    ser.close() # should be in receive thread so it closes after reading whole line
    print('rcvstate: finished thread')

# thread for sending commands over USB to STM32
# use queue so can send commands from multiple sources
def sendCmd():
   i=0
   print('sendCMD: started thread') 
   while not sendQ.empty():
       message = sendQ.get()  # flush any initial message command queue
   while not sendStop.is_set():
       time.sleep(0.001)   # give other threads time to run
       if not sendQ.empty():
       # get message if any from command queue
           message = sendQ.get()
#           print('sendCmd %d: message=%s' % (i, message))
           ser.write(message)   # send text to STM32, format is command word in text followed by short
           i=i+1 
   print('sendCmd: finished thread')

def makeCmd(command, value):
    textval = "{0}".format("%-6d" % value)  # convert command value to string, left justify
    messageString = command.encode('utf8') + b' '+ textval.encode('utf8') +b'\n'
    sendQ.put(messageString)
    

def control_loop(): 
    i = 0;
    state = StateStruct()
    print('control_loop- waiting for STM32READY\n')
    # makeCmd('PRNTWAIT', 5000)   # set wait time for state update in ms
    time.sleep(1)    # check periodically for start    
    while controlStop.is_set():
        time.sleep(1)    # check periodically for start    
    makeCmd('PRNWAIT', 100)   # set wait time for state update in ms
    time.sleep(3)
    print('control_loop: started thread')
    while ((i < 1000) and (not controlStop.is_set())):
        if not stateQ.empty():
            state = stateQ.get()
            # print('state.time = %f\n' % (state.time))
            value = 500 + 1000*np.cos(2*np.pi*state.time/30)
            makeCmd('PFRQ1', value)
            makeCmd('PFRQ2', -value)
            i = i+1 
            if ((i%10) == 0):
                print('step %d  stateQ size= %d' % (i,stateQ.qsize()))
            time.sleep(0.001)  # should run at state update rate
        else:
#            print('stateQ empty')
            time.sleep(0.001)
    print('control_loop: finished thread')




def writeFileHeader(dataFileName):
    fileout = open(dataFileName,'w')
    #write out parameters in format which can be imported to Excel
    today = time.localtime()
    date = str(today.tm_year)+'/'+str(today.tm_mon)+'/'+str(today.tm_mday)+'  '
    date = date + str(today.tm_hour) +':' + str(today.tm_min)+':'+str(today.tm_sec)
    fileout.write('"Data file recorded ' + date + '"\n')
    fileout.write('" time  hx711, qdec3, qdec5, adc8,  adc9, adc10, adc11, adc12, adc13, adc14, adc15"\n')
    fileout.close()

# debug version- debugger has trouble with threads
def main_test():
    print("Data Logging for STM32, with USB connection- test threads\n")
    rcvStop.clear()
    rcvstate()   # run directly for debugging outside thread
    

    
def main():
    print("Data Logging for STM32, with USB connection\n")
    stateThread = threading.Thread(group=None, target=rcvstate, name="stateThread")
    stateThread.daemon = False  # want clean file close
    rcvStop.clear()
    stateThread.start()
    time.sleep(5)  # give time to catch up with printing

# =============================================================================
#   be ready to send commands when control thread starts  
    sendThread =threading.Thread(group=None, target=sendCmd, name="sendThread")
    sendThread.daemon = False  # want clean file close
    sendStop.clear()
    sendThread.start()
    time.sleep(2) # give time before control thread starts
# =============================================================================
    controlStop.set()  # only start control loop if get STM32READY message
    controlThread =threading.Thread(group=None, target=control_loop, name="controlThread")
    controlThread.daemon = False  # want clean file close
    # controlStop.clear()   
    # for debugging, start control_loop() outside thread
    # control_loop()
    controlThread.start()
    

   
    print('Threads started. ctrl C to quit')
    # print(threading.enumerate())
    # Loop infinitely waiting for commands or until the user types quit or ctrl-c
    while True:
         #### if keyboard input is needed, it should be in thread to avoid blocking
        # Read keyboard input from the user
# =============================================================================
#         if (sys.version_info > (3, 0)):
#             message = input('')  # Python 3 compatibility
#         else:
#             message = raw_input('')  # Python 2 compatibility
# #        print('input message=%s' %(message))
#         # If user types quit then lets exit and close the socket
#         if 'quit' in message:
#             print("begin quit")
#             rcvStop.set()  # set stop variable
#             break
#         else:
#             sendQ.put(message.encode('utf8')+b'\n\r')
# =============================================================================
        time.sleep(0.5)  # give threads time to run
    print('Quit keyboard input loop')
    
  
    print("End of main. Closing threads")
    sendStop.set()
    rcvStop.set()  # set stop variable for thread
    controlStop.set()
    sleep(1.0) # wait for threads to close
    stateThread.join()   # wait for termination of state thread    
    sendThread.join()
    controlThread.join()
#    exit()      
#    sys.exit()
    

#Provide a try-except over the whole main function
# for clean exit. 
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt as e:
        print('Keyboard Interrupt!')
        sendStop.set()
        rcvStop.set()  # set stop variable for thread
        controlStop.set()
        sleep(3.0) # wait for threads to close
        ser.close()
    except OSError as error:
        print(error)     # the exception instance
        print(error.args)      # arguments stored in .args
        print("IO Error.")
        ser.close()
    finally:
        ser.close()
        print("normal exit")
        # should also close file
 #       exit()
        
