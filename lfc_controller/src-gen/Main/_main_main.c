#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 23 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
DAC_HandleTypeDef hdac;
TIM_HandleTypeDef htim2;


static void MX_TIM2_Init(void) {
  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 10;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK) {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
    Error_Handler();
  }
}

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

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 97 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Initialize GPIOs
    MX_GPIO_Init();
    MX_TIM2_Init();
    MX_DAC_Init();
    
    // Start Peripherals
    HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
    
    // Initial print
    printf("hello world\r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct s {
        _serial_trigger_t* trigger;
    
    } s;
    s.trigger = &(self->_lf_s.trigger);
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // lf_set(s.trigger, true);
    printf("encoder: %d\r\n", TIM2->CNT);
    
    // HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, 0);
    // HAL_UART_Receive (&huart2, Rx_data, 4, 100);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_2(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 119 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // printf("PRINT! counter: %d\r\n", self->counter);
    if (self->sign == 1) {
      self->counter = self->counter + 10;
    } else {
      self->counter = self->counter - 10;
    }
    
    HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, self->counter);
    
    if(self->counter >= 4090) {
      self->sign = 0;
    }
    
    if(self->counter <= 0) {
      self->sign = 1;
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_3(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct s {
        _serial_read_t* read;
    
    } s;
    s.read = self->_lf_s.read;
    #line 138 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->curr = s.read->value;
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_s_width = -2;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_s.read_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_s.read_reactions[0] = &self->_lf__reaction_3;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_s.read_trigger.reactions = self->_lf_s.read_reactions;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_s.read_trigger.last = NULL;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_s.read_trigger.number_of_reactions = 1;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #ifdef FEDERATED
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_s.read_trigger.physical_time_of_arrival = NEVER;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #endif // FEDERATED
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.number = 1;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.self = self;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.name = "?";
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.number = 2;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.function = _main_mainreaction_function_2;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.self = self;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.name = "?";
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.number = 3;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.function = _main_mainreaction_function_3;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.self = self;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.name = "?";
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.last = NULL;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_2;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.last = NULL;
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2_reactions[0] = &self->_lf__reaction_1;
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.reactions = &self->_lf__t2_reactions[0];
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.number_of_reactions = 1;
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t2.physical_time_of_arrival = NEVER;
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
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
