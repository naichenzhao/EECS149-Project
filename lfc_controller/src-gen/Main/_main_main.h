#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#include "_serial.h"
#include "_dac.h"
#include "_pid_controller.h"
#include "_qdec.h"
#ifndef TOP_LEVEL_PREAMBLE_2005776325_H
#define TOP_LEVEL_PREAMBLE_2005776325_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include <stdio.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 49 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int counter;
    #line 50 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int32_t encoder_count;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int sign;
    struct {
        #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
        _pid_controller_target_pos_t target_pos;
        #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
        _pid_controller_out_t* out;
        #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
        trigger_t out_trigger;
        #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
        reaction_t* out_reactions[1];
    } _lf_pid_controller;
    int _lf_pid_controller_width;
    struct {
        #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
        _qdec_trigger_t trigger;
        #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
        _qdec_read_t* read;
        #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
        trigger_t read_trigger;
        #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
        reaction_t* read_reactions[1];
    } _lf_qdec;
    int _lf_qdec_width;
    #line 57 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_0;
    #line 66 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_1;
    #line 98 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_2;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_3;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_4;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__t;
    #line 41 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__t_reactions[1];
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__update;
    #line 42 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__update_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
