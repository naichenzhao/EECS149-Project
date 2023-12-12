#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 23 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
UART_HandleTypeDef huart1;
static void* action;

uint8_t rx_data[6];
uint8_t rx_buffer[100];

static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0, 0};

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_RESET);

    /*Configure GPIO pin : LD5_Pin */
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

static void MX_USART1_UART_Init(void) {
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
  // printf("recieved %d \r\n", rx_data[0]);
  HAL_UART_Receive_IT(&huart1, rx_data, 1);

  if (rx_data[0] > 100) {
    change_FC();
  }

}

void change_FC() {
  printf("Triggered Action \r\n");
  lf_schedule(action, 0);
}

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 94 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Initialize GPIOs
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    HAL_UART_Receive_IT(&huart1, rx_data, 1);
    
    // Initial print
    printf("Starting up...\r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _main_main_force_triggered_t* force_triggered = &self->_lf_force_triggered;
    #line 104 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    action = force_triggered;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_2(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _main_main_force_triggered_t* force_triggered = &self->_lf_force_triggered;
    // Set the fields of the action struct to match the current trigger.
    force_triggered->is_present = (bool)self->_lf__force_triggered.status;
    force_triggered->has_value = ((self->_lf__force_triggered.tmplt.token) != NULL && (self->_lf__force_triggered.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)force_triggered, (self->_lf__force_triggered.tmplt.token));
    lf_critical_section_exit(self->base.environment);
    reactor_mode_t* FORCE_CONTROL = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_FORCE_CONTROL_change_type = reset_transition;
    #line 109 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    lf_set_mode(FORCE_CONTROL);
    self->pos = 0;
    printf("Force Detected \r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_3(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    reactor_mode_t* POS_CONTROL = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_POS_CONTROL_change_type = reset_transition;
    #line 117 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    lf_set_mode(POS_CONTROL);
    printf("Returning State \r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_4(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 123 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    if (self->pos < 0) {
      self->pos = 0;
    } else {
      self->pos = -20000;
    }
    printf("current state: %d \r\n", self->pos);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_5(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pid_controller {
        _pid_controller_target_pos_t* target_pos;
    
    } pid_controller;
    pid_controller.target_pos = &(self->_lf_pid_controller.target_pos);
    #line 133 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    lf_set(pid_controller.target_pos, self->pos);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_6(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct qdec {
        _qdec_trigger_t* trigger;
    
    } qdec;
    qdec.trigger = &(self->_lf_qdec.trigger);
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    lf_set(qdec.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_7(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct qdec {
        _qdec_read_t* read;
    
    } qdec;
    qdec.read = self->_lf_qdec.read;
    #line 141 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->encoder_count = qdec.read->value;
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf_force_triggered._base.trigger = &self->_lf__force_triggered;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf_force_triggered.parent = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_pid_controller_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_qdec_width = -2;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_qdec.read_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_qdec.read_reactions[0] = &self->_lf__reaction_7;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_qdec.read_trigger.reactions = self->_lf_qdec.read_reactions;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_qdec.read_trigger.last = NULL;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_qdec.read_trigger.number_of_reactions = 1;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #ifdef FEDERATED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_qdec.read_trigger.physical_time_of_arrival = NEVER;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #endif // FEDERATED
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.number = 1;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.self = self;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.name = "?";
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.number = 2;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.function = _main_mainreaction_function_2;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.self = self;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.name = "?";
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.number = 3;
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.function = _main_mainreaction_function_3;
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.self = self;
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.name = "?";
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.number = 4;
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.function = _main_mainreaction_function_4;
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.self = self;
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.name = "?";
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.number = 5;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.function = _main_mainreaction_function_5;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.self = self;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.name = "?";
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_5.mode = NULL;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.number = 6;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.function = _main_mainreaction_function_6;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.self = self;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.name = "?";
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_6.mode = NULL;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.number = 7;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.function = _main_mainreaction_function_7;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.self = self;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.STP_handler = NULL;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.name = "?";
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_7.mode = NULL;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos.last = NULL;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos_reactions[0] = &self->_lf__reaction_3;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos_reactions[1] = &self->_lf__reaction_4;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos.reactions = &self->_lf__change_pos_reactions[0];
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos.number_of_reactions = 2;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__change_pos.physical_time_of_arrival = NEVER;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__change_pos.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__change_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.last = NULL;
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update_reactions[0] = &self->_lf__reaction_5;
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update_reactions[1] = &self->_lf__reaction_6;
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.reactions = &self->_lf__update_reactions[0];
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.number_of_reactions = 2;
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.physical_time_of_arrival = NEVER;
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__update.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup_reactions[1] = &self->_lf__reaction_1;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 2;
    self->_lf__startup.is_timer = false;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__force_triggered.last = NULL;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__force_triggered.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__force_triggered_reactions[0] = &self->_lf__reaction_2;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__force_triggered.reactions = &self->_lf__force_triggered_reactions[0];
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__force_triggered.number_of_reactions = 1;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__force_triggered.physical_time_of_arrival = NEVER;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__force_triggered.is_physical = true;
    
    self->_lf__force_triggered.tmplt.type.element_size = 0;
    self->_lf_force_triggered.type.element_size = 0;
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 107 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 107 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[0].name = "POS_CONTROL";
    #line 107 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 107 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[0].flags = 0;
    #line 115 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 115 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[1].name = "FORCE_CONTROL";
    #line 115 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 115 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
