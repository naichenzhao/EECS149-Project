#include "include/api/api.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 21 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    printf("hello world\r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    printf("Timer print\r\n");
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.number = 1;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.self = self;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.name = "?";
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__t.last = NULL;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    #ifdef FEDERATED
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
