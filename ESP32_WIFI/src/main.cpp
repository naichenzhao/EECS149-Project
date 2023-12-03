#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <HardwareSerial.h>
#include <vector>


const char* ssid = "WirelessFT";
const char* password = "03xBbVFx";

WiFiClient client;
const uint16_t telnetPort = 23;  // Standard Telnet port
const char* sensorIp = "192.168.1.137";  // Replace with your sensor's IP

void connectTelnet() {
  if (client.connect(sensorIp, telnetPort)) {
    Serial.println("Connected to sensor");
  } else {
    Serial.println("Connection failed");
  }
}

void telnetCommand(String command) {
  if (client.connected()) {
    client.print(command + "\r\n");
  }
}

WiFiUDP udp;

const char* udpAddress = "192.168.1.137"; // Replace with your server's IP address
const unsigned int udpPort = 49152;            // Replace with your server's UDP port

unsigned char udpCommandSequence = 0; // This would be incremented as needed
// Eigen::MatrixXd  sensor_counts;
unsigned short crcByte( unsigned short crc, char ch ) 
{
        static int ccitt_crc16_table[32*8] = 
        {
            0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
            0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
            0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
            0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
            0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
            0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
            0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
            0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
            0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
            0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
            0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
            0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
            0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
            0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
            0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
            0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
            0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
            0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
            0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
            0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
            0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
            0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
            0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
            0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
            0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
            0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
            0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
            0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
            0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
            0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
            0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
            0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
        };
        return (short) (ccitt_crc16_table[((crc >> 8) ^ ch) & 0xff] ^ (crc << 8));
}
// Function to calculate CRC, implement the actual CRC calculation needed
unsigned short crcBuf(const unsigned char* data, size_t length) {
    int i;
  short crc = 0x1234; // CRC seed.

  for (i = 0; i < length; i++) 
  {
    crc = crcByte(crc, data[i]);
  }
  return crc;
}


void udpStartStreaming() {
  // Construct the packet
  char buffer[10];
  buffer[0] = 0;
  buffer[1] = (unsigned char) (0x00FF & 10); // length
  buffer[2] = udpCommandSequence;            // seq-number
  buffer[3] = (unsigned char) 1;             // start_streaming
  buffer[4] = (unsigned char) 0;             // number of packets
  buffer[5] = (unsigned char) 0;
  buffer[6] = (unsigned char) 0; // 10
  buffer[7] = (unsigned char) 0; // 255;

  unsigned short crc = crcBuf( (unsigned char*)buffer, 8 );
  buffer[8] = (unsigned char) (crc >> 8);
  buffer[9] = (unsigned char) (crc & 0x00ff);

  // Send the packet
  udp.beginPacket(udpAddress, udpPort);
  unsigned int length = 10;
  udp.write((unsigned char*)buffer, length);
  udp.endPacket();

  Serial.print("udpStartStreaming: sent packet of ");
  Serial.print(length);
  Serial.println(" bytes");
}



void udpStopStreaming() 
{

  char buffer[6];
  buffer[0] = 0;
  buffer[1] = (unsigned char) (0x00FF & 6); // length including crc
  buffer[2] = udpCommandSequence;           // seq-number
  buffer[3] = (unsigned char) 2;            // stop_streaming

  unsigned short crc = crcBuf((unsigned char*) buffer, 4 );
  buffer[4] = (unsigned char) (crc >> 8);
  buffer[5] = (unsigned char) (crc & 0x00ff);

  unsigned int length = 6;
  udp.beginPacket(udpAddress, udpPort);
  udp.write((unsigned char*)buffer, length);
  udp.endPacket();
  Serial.print("udpStopStreaming: wrote  ");
  Serial.print(length);
  Serial.println(" bytes");
}



void udpPing() 
{

  char buffer[6];
  buffer[0] = 0;
  buffer[1] = (unsigned char) (0x00FF & 6); // length including crc
  buffer[2] = udpCommandSequence;           // seq-number
  buffer[3] = (unsigned char) 4;            // stop_streaming

  unsigned short crc = crcBuf((unsigned char*) buffer, 4 );
  buffer[4] = (unsigned char) (crc >> 8);
  buffer[5] = (unsigned char) (crc & 0x00ff);

  unsigned int length = 6;
  udp.beginPacket(udpAddress, udpPort);
  udp.write((unsigned char*)buffer, length);
  udp.endPacket();
  Serial.print("udpStopStreaming: wrote  ");
  Serial.print(length);
  Serial.println(" bytes");
}

void udpResetTelnetSocket() 
{
  char buffer[6];
  buffer[0] = 0;
  buffer[1] = (unsigned char) (0x00FF & 6); // length including crc
  buffer[2] = udpCommandSequence;           // seq-number
  buffer[3] = (unsigned char) 5;            // reset_telnet_socket

  unsigned short crc = crcBuf((unsigned char*) buffer, 4 );
  buffer[4] = (unsigned char) (crc >> 8);
  buffer[5] = (unsigned char) (crc & 0x00ff);

  unsigned int length = 6;
  udp.beginPacket(udpAddress, udpPort);
  udp.write((unsigned char*)buffer, length);
  udp.endPacket();
  Serial.print("udpStopStreaming: wrote  ");
  Serial.print(length);
  Serial.println(" bytes");
}

int parseInteger( char* buffer, int pos ) {
  int value = ((0x00ff & buffer[pos]) << 24)
            + ((0x00ff & buffer[pos+1]) << 16)
            + ((0x00ff & buffer[pos+2]) << 8)
            + ((0x00ff & buffer[pos+3]) << 0);
  return value;
}



std::vector<int>  decodeDataPacket( char* buffer, unsigned int n_bytes ) {
  // if (verbose > 2) ROS_INFO( "decodeDataPacket:" );
  std::vector<int> listOfIntegers;

   

  char hex[18] = "0123456789ABCDEF_";


  // if (verbose > 3) { // dump original packet
    for( unsigned int i=0; i < n_bytes; i++ ) {
      // printf( "%.2x ", (0x00ff & buffer[i]) );
    }
    // printf( "\n\n" );
    for( unsigned int i=0; i < n_bytes; i++ ) {
      int tmp = buffer[i];
      // printf( "%c%c ", hex[0x000F&(tmp>>4)], hex[0x000F&tmp] );
      if ((i % 20) == 19) printf( "\n" );
    }
   

  int pos = 18;
  int Fx = (parseInteger( buffer, pos+0 ));
  int Fy = (parseInteger( buffer, pos+4 ));
  int Fz = (parseInteger( buffer, pos+8 ));
  int Tx = (parseInteger( buffer, pos+12 ));
  int Ty = (parseInteger( buffer, pos+16 ));
  int Tz = (parseInteger( buffer, pos+20 ));
    Serial.print(Fx);
    Serial.print("    ");
    Serial.print(Fy);
    Serial.print("    ");
    Serial.print(Fz);
    Serial.print("    ");
    Serial.print(Tx);
    Serial.print("    ");
    Serial.print(Ty);
    Serial.print("    ");
    Serial.print(Tz);
    Serial.print("    ");

   // Add some integers to the list
    listOfIntegers.push_back(Fx);
    listOfIntegers.push_back(Fy);
    listOfIntegers.push_back(Fz);
    listOfIntegers.push_back(Tx);
    listOfIntegers.push_back(Ty);
    listOfIntegers.push_back(Tz);
    return listOfIntegers;
}


std::vector<int> readDataPacket()
{
    char buffer[2048];
    bzero( buffer, 2048 );

    int len = udp.read(buffer, 140); // Read up to 140 bytes
  
    return decodeDataPacket( buffer, 140 ); 
}



HardwareSerial mySerial(1); // Use UART1 (pins defined below)

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(udpPort); // Begin listening on the specified UDP port
  mySerial.begin(115200, SERIAL_8N1, 17, 16);
}

void loop() {
  // telnetCommand("ssid");
  // delay(10000);
  // Call the udpStartStreaming function to send the UDP packet
  udpStartStreaming();
  
  // Increment your sequence number or add other logic as needed
  udpCommandSequence++;

  int packetSize = udp.parsePacket();
  if (packetSize) {
    // Received a packet
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(udp.remotePort());

    // Read the packet into a buffer
    // char buffer[2048]; // Adjust the size as necessary for your data packets
    // int len = udp.read(buffer, 140); // Read up to 140 bytes
    // if (len > 0) {
    //   buffer[len] = 0; // Null-terminate the string
    // }

    // Process the packet
    // Serial.print("UDP packet contents: ");
    // Serial.println(buffer); 
    
    std::vector<int> dataToSend = readDataPacket(); // Example data

    for (int i = 0; i < 6; i++) {
        mySerial.write((byte *)&dataToSend[i], sizeof(dataToSend[i]));
    }

    delay(1000); // Send data every second
  }
  // For demonstration, wait 2 seconds between sends
  // delay(10);
}
