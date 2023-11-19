#include "include/api/api.h"
#include "include/core/platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
UART_HandleTypeDef huart2;

int _write(int file, char *ptr, int len) {
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}

static void MX_USART2_UART_Init(void) {
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : LD5_Pin */
    GPIO_InitStruct.Pin = LD5_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LD5_GPIO_Port, &GPIO_InitStruct);
}

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 65 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    // Initialize GPIOs
    MX_USART2_UART_Init();
    MX_GPIO_Init();
    
    // Initial print
    printf("hello world\r\n");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 74 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    HAL_GPIO_TogglePin(LD5_GPIO_Port, LD5_Pin);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _main_mainreaction_function_2(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    printf("Timer2 print. Counter: %d\r\n", self->counter);
    self->counter = self->counter + 1;
    HAL_GPIO_TogglePin(LD5_GPIO_Port, LD5_Pin);
}
#include "include/api/set_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)_lf_new_reactor(sizeof(_main_main_main_self_t));
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.number = 0;
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.self = self;
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.name = "?";
    #line 64 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.number = 1;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.self = self;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.name = "?";
    #line 73 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.number = 2;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.function = _main_mainreaction_function_2;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.self = self;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.name = "?";
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t.last = NULL;
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #ifdef FEDERATED
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 60 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t2.last = NULL;
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t2_reactions[0] = &self->_lf__reaction_2;
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t2.reactions = &self->_lf__t2_reactions[0];
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t2.number_of_reactions = 1;
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #ifdef FEDERATED
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    self->_lf__t2.physical_time_of_arrival = NEVER;
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    #endif // FEDERATED
    self->_lf__t2.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
