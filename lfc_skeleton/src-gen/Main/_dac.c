#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/DAC/DAC.h"
#include "_dac.h"
// *********** From the preamble, verbatim:
#line 18 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
DAC_HandleTypeDef hdac;
static void MX_DAC_Init(void) {
    DAC_ChannelConfTypeDef sConfig = {0};
    hdac.Instance = DAC1;
    if (HAL_DAC_Init(&hdac) != HAL_OK) {
      Error_Handler();
    }

    sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
    sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
    if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_2) != HAL_OK) {
      Error_Handler();
    }
}

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _dacreaction_function_0(void* instance_args) {
    _dac_self_t* self = (_dac_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 35 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    MX_DAC_Init();
    HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _dacreaction_function_1(void* instance_args) {
    _dac_self_t* self = (_dac_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _dac_setvalue_t* setvalue = self->_lf_setvalue;
    int setvalue_width = self->_lf_setvalue_width; SUPPRESS_UNUSED_WARNING(setvalue_width);
    #line 40 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    if(setvalue->value < 0) {
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, -setvalue->value);
    } else {
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, setvalue->value);
    }
}
#include "include/api/set_undef.h"
_dac_self_t* new__dac() {
    _dac_self_t* self = (_dac_self_t*)_lf_new_reactor(sizeof(_dac_self_t));
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    // Set input by default to an always absent default input.
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf_setvalue = &self->_lf_default__setvalue;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    // Set the default source reactor pointer
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf_default__setvalue._base.source_reactor = (self_base_t*)self;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.number = 0;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.function = _dacreaction_function_0;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.self = self;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.name = "?";
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.number = 1;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.function = _dacreaction_function_1;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.self = self;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.name = "?";
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__setvalue.last = NULL;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__setvalue.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__setvalue_reactions[0] = &self->_lf__reaction_1;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__setvalue.reactions = &self->_lf__setvalue_reactions[0];
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__setvalue.number_of_reactions = 1;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    #ifdef FEDERATED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    self->_lf__setvalue.physical_time_of_arrival = NEVER;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    #endif // FEDERATED
    self->_lf__setvalue.tmplt.type.element_size = sizeof(int32_t);
    return self;
}
