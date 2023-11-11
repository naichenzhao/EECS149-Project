#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1631959070_H
#define TOP_LEVEL_PREAMBLE_1631959070_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
typedef struct {
    struct self_base_t base;
    
    
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_REF/src/Main.lf"
    reaction_t _lf__reaction_0;
    #line 24 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_REF/src/Main.lf"
    reaction_t _lf__reaction_1;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_REF/src/Main.lf"
    trigger_t _lf__t;
    #line 18 "/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_REF/src/Main.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
