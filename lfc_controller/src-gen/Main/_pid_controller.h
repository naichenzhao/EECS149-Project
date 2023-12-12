#ifndef _PID_CONTROLLER_H
#define _PID_CONTROLLER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_371932487_H
#define TOP_LEVEL_PREAMBLE_371932487_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_current_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_target_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_out_t;
typedef struct {
    struct self_base_t base;
    #line 14 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    float Kp;
    #line 14 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    float Ki;
    #line 14 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    float Kd;
    #line 19 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    int32_t last_pos;
    #line 20 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    interval_t prev_time;
    #line 21 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    float Kw;
    #line 23 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    float error_i;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    _pid_controller_current_pos_t* _lf_current_pos;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // width of -2 indicates that it is not a multiport.
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    int _lf_current_pos_width;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // Default input (in case it does not get connected)
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    _pid_controller_current_pos_t _lf_default__current_pos;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    _pid_controller_target_pos_t* _lf_target_pos;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // width of -2 indicates that it is not a multiport.
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    int _lf_target_pos_width;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    // Default input (in case it does not get connected)
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    _pid_controller_target_pos_t _lf_default__target_pos;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    _pid_controller_out_t _lf_out;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    int _lf_out_width;
    #line 25 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    reaction_t _lf__reaction_0;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    trigger_t _lf__current_pos;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    reaction_t* _lf__current_pos_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    trigger_t _lf__target_pos;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf"
    reaction_t* _lf__target_pos_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _pid_controller_self_t;
_pid_controller_self_t* new__pid_controller();
#endif // _PID_CONTROLLER_H
