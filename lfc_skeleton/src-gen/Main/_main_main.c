#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 18 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

    /*Configure GPIO pin : LD5_Pin */
    GPIO_InitStruct.Pin = GPIO_PIN_4;
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
    
    #line 37 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    // Initialize GPIOs
    MX_GPIO_Init();
    
    // Initial print
    printf("hello world\r\n");
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
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
