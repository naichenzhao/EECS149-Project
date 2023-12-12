#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 23 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
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

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 58 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Initialize GPIOs
    MX_GPIO_Init();
    
    // Initial print
    printf("hello world\r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pid_controller {
        _pid_controller_target_pos_t* target_pos;
    
    } pid_controller;
    pid_controller.target_pos = &(self->_lf_pid_controller.target_pos);
    #line 67 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // if (self->sign == 1) {
    //   self->counter = self->counter + 10;
    // } else {
    //   self->counter = self->counter - 10;
    // }
    
    if (self->counter == 0) {
      self->counter = 10000;
    } else {
      self->counter = 0;
    }
    
    lf_set(pid_controller.target_pos, self->counter);
    
    
    
    // lf_set(dac.setvalue, self->counter);
    // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, self->counter > 0);
    
    
    // printf("counter: %d\r\n", self->counter);
    
    // if(self->counter >= 4090) {
    //   self->sign = 0;
    // }
    // if(self->counter <= -4090) {
    //   self->sign = 1;
    // }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_2(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct qdec {
        _qdec_trigger_t* trigger;
    
    } qdec;
    qdec.trigger = &(self->_lf_qdec.trigger);
    #line 99 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    lf_set(qdec.trigger, true);
    // printf("encoder: %d\r\n", qdec.read->value);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_3(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pid_controller {
        _pid_controller_out_t* out;
    
    } pid_controller;
    pid_controller.out = self->_lf_pid_controller.out;
    #line 104 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    bool dir = pid_controller.out->value > 0;
    bool lim = pid_controller.out->value > -10 && pid_controller.out->value < 10;
    // printf("out: %ld\r\n", pid_controller.out->value);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, dir);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, lim);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_4(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct qdec {
        _qdec_read_t* read;
    
    } qdec;
    qdec.read = self->_lf_qdec.read;
    #line 112 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->encoder_count = qdec.read->value;
    // printf("encoder: %ld dac: %d\r\n", self->encoder_count, self->counter);
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_pid_controller_width = -2;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_pid_controller.out_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_pid_controller.out_reactions[0] = &self->_lf__reaction_3;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_pid_controller.out_trigger.reactions = self->_lf_pid_controller.out_reactions;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_pid_controller.out_trigger.last = NULL;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_pid_controller.out_trigger.number_of_reactions = 1;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #ifdef FEDERATED
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_pid_controller.out_trigger.physical_time_of_arrival = NEVER;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #endif // FEDERATED
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
    self->_lf_qdec.read_reactions[0] = &self->_lf__reaction_4;
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
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.number = 1;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.self = self;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.name = "?";
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.number = 2;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.function = _main_mainreaction_function_2;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.self = self;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.name = "?";
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.number = 3;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.function = _main_mainreaction_function_3;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.self = self;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.name = "?";
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.number = 4;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.function = _main_mainreaction_function_4;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.self = self;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.name = "?";
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.last = NULL;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.last = NULL;
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update_reactions[0] = &self->_lf__reaction_2;
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.reactions = &self->_lf__update_reactions[0];
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.number_of_reactions = 1;
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__update.physical_time_of_arrival = NEVER;
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__update.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
