#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/TestReactor.h"
#include "_testreactor.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _testreactorreaction_function_0(void* instance_args) {
    _testreactor_self_t* self = (_testreactor_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _testreactor_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _testreactor_resp_t* resp = &self->_lf_resp;
    #line 115 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    lf_set(resp, 5);
}
#include "include/api/set_undef.h"
_testreactor_self_t* new__testreactor() {
    _testreactor_self_t* self = (_testreactor_self_t*)_lf_new_reactor(sizeof(_testreactor_self_t));
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Set input by default to an always absent default input.
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Set the default source reactor pointer
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.function = _testreactorreaction_function_0;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__trigger.last = NULL;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_0;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__trigger.number_of_reactions = 1;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #ifdef FEDERATED
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}
