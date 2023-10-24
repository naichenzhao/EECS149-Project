#include "include/api/api.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 19 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 18 "/Users/naichenzhao/Desktop/LFC_Porting/lf_testing/lf_platformtest/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
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
