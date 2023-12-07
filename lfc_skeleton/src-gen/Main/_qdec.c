#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Encoder/QDEC.h"
#include "_qdec.h"
// *********** From the preamble, verbatim:
#line 19 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
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

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _qdecreaction_function_0(void* instance_args) {
    _qdec_self_t* self = (_qdec_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 52 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    MX_TIM2_Init();
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _qdecreaction_function_1(void* instance_args) {
    _qdec_self_t* self = (_qdec_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _qdec_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _qdec_read_t* read = &self->_lf_read;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    lf_set(read, TIM2->CNT);
}
#include "include/api/set_undef.h"
_qdec_self_t* new__qdec() {
    _qdec_self_t* self = (_qdec_self_t*)_lf_new_reactor(sizeof(_qdec_self_t));
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    // Set input by default to an always absent default input.
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    // Set the default source reactor pointer
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.number = 0;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.function = _qdecreaction_function_0;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.self = self;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.name = "?";
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.number = 1;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.function = _qdecreaction_function_1;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.self = self;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.name = "?";
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__trigger.last = NULL;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__trigger.number_of_reactions = 1;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #ifdef FEDERATED
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}
