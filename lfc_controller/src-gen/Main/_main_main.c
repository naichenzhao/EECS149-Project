#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 22 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
DAC_HandleTypeDef hdac;
extern UART_HandleTypeDef huart2;

static uint8_t rx_data[6];

static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // /*Configure GPIO pin Output Level */
    // HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);

    // /*Configure GPIO pin : LD5_Pin */
    // GPIO_InitStruct.Pin = LD5_Pin;
    // GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    // GPIO_InitStruct.Pull = GPIO_NOPULL;
    // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    // HAL_GPIO_Init(LD5_GPIO_Port, &GPIO_InitStruct);
}

static void MX_DAC_Init(void) {
  DAC_ChannelConfTypeDef sConfig = {0};
  hdac.Instance = DAC1;
  if (HAL_DAC_Init(&hdac) != HAL_OK) {
    Error_Handler();
  }

  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK) {
    Error_Handler();
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
  printf("recieved %c \r\n", rx_data[0]);
  // HAL_UART_Transmit(&huart2, rx_data, 6, 10);
  // HAL_UART_Receive_DMA(&huart2, UART2_rxBuffer, 12);

  // HAL_UART_Transmit(&huart2, rx_data, 6, 100);
  HAL_UART_Receive_IT(&huart2, rx_data, 1);
}

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 74 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Initialize GPIOs
    MX_GPIO_Init();
    MX_DAC_Init();
    
    
    HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
    HAL_UART_Receive_IT(&huart2, rx_data, 1);
    
    
    // Initial print
    printf("hello world\r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // HAL_GPIO_TogglePin(LD5_GPIO_Port, LD5_Pin);
    // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, 0);
    // HAL_UART_Receive (&huart2, Rx_data, 4, 100);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_2(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 94 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // printf("PRINT! counter: %d\r\n", self->counter);
    // if (self->sign == 1) {
    //   self->counter = self->counter + 100;
    // } else {
    //   self->counter = self->counter - 100;
    // }
    
    // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, self->counter);
    
    // if(self->counter >= 4090) {
    //   self->sign = 0;
    // }
    
    // if(self->counter <= 0) {
    //   self->sign = 1;
    // }
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.number = 1;
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.self = self;
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.name = "?";
    #line 87 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.number = 2;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.function = _main_mainreaction_function_2;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.self = self;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.name = "?";
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.last = NULL;
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 68 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.last = NULL;
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2_reactions[0] = &self->_lf__reaction_2;
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.reactions = &self->_lf__t2_reactions[0];
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.number_of_reactions = 1;
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.physical_time_of_arrival = NEVER;
    #line 69 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t2.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}
