#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/PID/PID_Controller.h"
#include "_pid_controller.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _pid_controllerreaction_function_0(void* instance_args) {
    _pid_controller_self_t* self = (_pid_controller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _pid_controller_target_pos_t* target_pos = self->_lf_target_pos;
    int target_pos_width = self->_lf_target_pos_width; SUPPRESS_UNUSED_WARNING(target_pos_width);
    _pid_controller_current_pos_t* current_pos = self->_lf_current_pos;
    int current_pos_width = self->_lf_current_pos_width; SUPPRESS_UNUSED_WARNING(current_pos_width);
    _pid_controller_out_t* out = &self->_lf_out;
    #line 26 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    instant_t now = lf_time_logical();
    interval_t interval = now - self->prev_time;
    
    float error_p = target_pos->value - current_pos->value;
    float error_d = (current_pos->value - self->last_pos) / interval;
    self->error_i = error_p + (self->Kw * self->error_i);
    
    float pid_out = self->Kp * error_p + self->Ki * self->error_i + self->Kd * error_d;
    lf_set(out, pid_out);
    
    self->last_pos = current_pos->value;
    self->prev_time = now;
}
#include "include/api/set_undef.h"
_pid_controller_self_t* new__pid_controller() {
    _pid_controller_self_t* self = (_pid_controller_self_t*)_lf_new_reactor(sizeof(_pid_controller_self_t));
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // Set input by default to an always absent default input.
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_current_pos = &self->_lf_default__current_pos;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // Set the default source reactor pointer
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_default__current_pos._base.source_reactor = (self_base_t*)self;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // Set input by default to an always absent default input.
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_target_pos = &self->_lf_default__target_pos;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // Set the default source reactor pointer
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf_default__target_pos._base.source_reactor = (self_base_t*)self;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.number = 0;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.function = _pid_controllerreaction_function_0;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.self = self;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.name = "?";
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__current_pos.last = NULL;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__current_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__current_pos_reactions[0] = &self->_lf__reaction_0;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__current_pos.reactions = &self->_lf__current_pos_reactions[0];
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__current_pos.number_of_reactions = 1;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #ifdef FEDERATED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__current_pos.physical_time_of_arrival = NEVER;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #endif // FEDERATED
    self->_lf__current_pos.tmplt.type.element_size = sizeof(int32_t);
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__target_pos.last = NULL;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__target_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__target_pos_reactions[0] = &self->_lf__reaction_0;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__target_pos.reactions = &self->_lf__target_pos_reactions[0];
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__target_pos.number_of_reactions = 1;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #ifdef FEDERATED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    self->_lf__target_pos.physical_time_of_arrival = NEVER;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    #endif // FEDERATED
    self->_lf__target_pos.tmplt.type.element_size = sizeof(int32_t);
    return self;
}
