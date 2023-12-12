/* low level reading serial input using interrupts. 
* use \n to end each line
* Need interrupts to continuously read serial, as thread can be interrupted in middle of reading a line
* using polling
* line Buffer uses hand shaking with uart_input_thread(void) to 
* prevent reading partial data
*/

#include "stm32f4xx.h"
#include "stm32f4xx_ll_usart.h"
#include <sys/printk.h>
#include <zephyr.h>
#include "../../src/pid.h"
#include <drivers/gpio.h>

#define UART_BUFFER_SIZE 128
// USART needs to be high priority to avoid missing input at 150 char/sec = every 6.6 us
// lowest priority is 15
//#define USART2_Priority (IRQ_PRIO_LOWEST - 13)
#define USART2_Priority (2)
#define USART2_IRQ_FLAGS 0
#define USART2_ISR_ARG 0

#define USART1_Priority (2)
#define USART1_IRQ_FLAGS 0
#define USART1_ISR_ARG 0

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern void led_toggle();
void uart_interrupt_init(void);
char console_getchar(void);

// indexes for character input ring buffer
char line1_avail, line2_avail; // line 1 buffer is ready to be copied
char line1_read, line2_read; // line1 buffer has been read, and is ready to be over written

// Buffer to store received data
volatile uint8_t rxBuffer[UART_BUFFER_SIZE];
volatile uint8_t rxIndex = 0;

int last_count = 0;

#define EN_SWITCH DT_ALIAS(en0)
#define EN_SWITCH_LABEL DT_GPIO_LABEL(EN_SWITCH, gpios)
#define EN_SWITCH_PIN DT_GPIO_PIN(EN_SWITCH, gpios)

const struct device *en_switch_dev;

/* polling based console_getchar()*/
/* 
char console_getchar()
{ char c;
  while(!LL_USART_IsActiveFlag_RXNE(USART2))
  { k_msleep(1); }
  c = LL_USART_ReceiveData8(USART2);
  return(c);
}
 */

/* interrupt based console_getchar()using ring buffer*/
char console_getchar()
{ char c;
  static uint8_t getcharIndex = 0;
  while(rxIndex == getcharIndex)
  { k_msleep(1); } // let other threads run, getchar has caught up with rxIndex
  c = rxBuffer[getcharIndex++];
  if (getcharIndex >= UART_BUFFER_SIZE) 
  {  getcharIndex = 0; // Buffer overflow handling, reset index
  }
  return(c);
}


//void USART2_IRQHandler(void *arg) 
ISR_DIRECT_DECLARE(USART2_IRQHandler)
{ char rxData; 
    irq_disable(USART2_IRQn);  // don't allow another usart interrupt until this one is handled/cleared
// check for over run, interrupt not responding in time
    if (LL_USART_IsActiveFlag_ORE(USART2)) 
    { printk("# serial Rx over run\n");
      LL_USART_ClearFlag_ORE(USART2);
    }
    if (LL_USART_IsActiveFlag_RXNE(USART2))  // can be non-empty, and over run at same time
    {   LL_USART_ClearFlag_ORE(USART2);
      if (gpio_pin_get(en_switch_dev, EN_SWITCH_PIN)) {
          set_target(0);
      } 
    }
    
    irq_enable(USART2_IRQn);
    return(0); // The function should return nonzero status if a scheduling decision should potentially be made.  
}


void uart_interrupt_init()
{   // uint32_t int_vector;

    en_switch_dev = device_get_binding(EN_SWITCH_LABEL);
    gpio_pin_configure(en_switch_dev, EN_SWITCH_PIN, GPIO_INPUT);
    if (!en_switch_dev)
    {
      printk("\nCannot find EN_SWITCH device!\n");
      return;
    }
    LL_USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.BaudRate = 115200;
    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
    USART_InitStruct.Parity = LL_USART_PARITY_NONE;
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl =  LL_USART_HWCONTROL_NONE; 
   
    LL_USART_Init(USART2, &USART_InitStruct);
    LL_USART_EnableIT_RXNE(USART2); // enable receiver not empty interrupt
    LL_USART_EnableIT_ERROR(USART2); // enable interrupt on errors, such as overRun error
    LL_USART_Enable(USART2);

    /* Zephyr interrupt installer for vector table */
    IRQ_DIRECT_CONNECT(USART2_IRQn, USART2_Priority, USART2_IRQHandler, USART2_IRQ_FLAGS);
 //   IRQ_CONNECT(USART2_IRQn, USART2_Priority, USART2_IRQHandler, USART2_ISR_ARG, USART2_IRQ_FLAGS);
    irq_enable(USART2_IRQn);

}







