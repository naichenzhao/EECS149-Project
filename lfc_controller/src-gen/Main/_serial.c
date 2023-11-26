#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Serial/Serial.h"
#include "_serial.h"
// *********** From the preamble, verbatim:
#line 20 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
extern UART_HandleTypeDef huart2;
uint8_t rx_data[6];
uint8_t rx_buffer[100];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

  printf("recieved %c \r\n", rx_data[0]);
  HAL_UART_Receive_IT(&huart2, rx_data, 1);

}

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _serialreaction_function_0(void* instance_args) {
    _serial_self_t* self = (_serial_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 33 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    HAL_UART_Receive_IT(&huart2, rx_data, 1);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _serialreaction_function_1(void* instance_args) {
    _serial_self_t* self = (_serial_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _serial_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _serial_read_t* read = &self->_lf_read;
    #line 37 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    printf("triggered: %c \r\n", rx_data[0]);
    lf_set(read, rx_data);
}
#include "include/api/set_undef.h"
_serial_self_t* new__serial() {
    _serial_self_t* self = (_serial_self_t*)_lf_new_reactor(sizeof(_serial_self_t));
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    // Set input by default to an always absent default input.
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    // Set the default source reactor pointer
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.number = 0;
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.function = _serialreaction_function_0;
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.self = self;
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.name = "?";
    #line 32 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.number = 1;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.function = _serialreaction_function_1;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.self = self;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.name = "?";
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__trigger.last = NULL;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__trigger.number_of_reactions = 1;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #ifdef FEDERATED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}
