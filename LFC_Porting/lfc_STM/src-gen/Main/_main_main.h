#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1881218633_H
#define TOP_LEVEL_PREAMBLE_1881218633_H
#include <stdio.h>
#include "stm32f4xx_hal.h"

#define LD5_Pin GPIO_PIN_5
#define LD5_GPIO_Port GPIOA
#endif
typedef struct {
    struct self_base_t base;
    
    #line 59 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    int counter;
    #line 61 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    reaction_t _lf__reaction_0;
    #line 70 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    reaction_t _lf__reaction_1;
    #line 74 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    reaction_t _lf__reaction_2;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    trigger_t _lf__t;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    reaction_t* _lf__t_reactions[1];
    #line 58 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    trigger_t _lf__t2;
    #line 58 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_STM/src/Main.lf"
    reaction_t* _lf__t2_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
