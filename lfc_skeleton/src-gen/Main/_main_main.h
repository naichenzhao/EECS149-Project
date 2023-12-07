#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1492156162_H
#define TOP_LEVEL_PREAMBLE_1492156162_H
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#endif
typedef struct {
    struct self_base_t base;
    
    
    #line 36 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_skeleton/src/Main.lf"
    reaction_t _lf__reaction_0;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
