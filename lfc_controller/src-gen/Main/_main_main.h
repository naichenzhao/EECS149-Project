#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#include "_serial.h"
#ifndef TOP_LEVEL_PREAMBLE_678801430_H
#define TOP_LEVEL_PREAMBLE_678801430_H
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"

#define LD5_Pin GPIO_PIN_5
#define LD5_GPIO_Port GPIOA
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#endif
typedef struct {
    struct self_base_t base;
    
    #line 90 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int counter;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int sign;
    #line 94 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    uint8_t* curr;
    struct {
        #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
        _serial_trigger_t trigger;
        #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
        _serial_read_t* read;
        #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
        trigger_t read_trigger;
        #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
        reaction_t* read_reactions[1];
    } _lf_s;
    int _lf_s_width;
    #line 96 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_0;
    #line 110 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_1;
    #line 118 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_2;
    #line 137 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_3;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__t;
    #line 88 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__t_reactions[1];
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__t2;
    #line 89 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__t2_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
