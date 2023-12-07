#ifndef _TESTREACTOR_H
#define _TESTREACTOR_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_836782867_H
#define TOP_LEVEL_PREAMBLE_836782867_H
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"

#define LD5_Pin GPIO_PIN_5
#define LD5_GPIO_Port GPIOA
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _testreactor_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _testreactor_resp_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    _testreactor_trigger_t* _lf_trigger;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // width of -2 indicates that it is not a multiport.
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int _lf_trigger_width;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    // Default input (in case it does not get connected)
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    _testreactor_trigger_t _lf_default__trigger;
    #line 112 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    _testreactor_resp_t _lf_resp;
    #line 112 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    int _lf_resp_width;
    #line 114 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t _lf__reaction_0;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    trigger_t _lf__trigger;
    #line 111 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf"
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _testreactor_self_t;
_testreactor_self_t* new__testreactor();
#endif // _TESTREACTOR_H
