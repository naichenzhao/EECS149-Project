#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#include "_dac.h"
#include "_pid_controller.h"
#include "_qdec.h"
#ifndef TOP_LEVEL_PREAMBLE_836782867_H
#define TOP_LEVEL_PREAMBLE_836782867_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _main_main_force_triggered_t;
typedef struct {
    struct self_base_t base;
    
    #line 84 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int pos;
    #line 85 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int32_t encoder_count;
    #line 86 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int sign;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    _main_main_force_triggered_t _lf_force_triggered;
    struct {
        #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
        _pid_controller_target_pos_t target_pos;
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
    #line 93 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_0;
    #line 103 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_1;
    #line 108 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_2;
    #line 116 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_3;
    #line 122 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_4;
    #line 132 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_5;
    #line 136 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_6;
    #line 140 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_7;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__change_pos;
    #line 77 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__change_pos_reactions[2];
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__update;
    #line 78 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__update_reactions[2];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[2];
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__force_triggered;
    #line 91 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__force_triggered_reactions[1];
    reactor_mode_t _lf__modes[2];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
