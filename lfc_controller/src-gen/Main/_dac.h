#ifndef _DAC_H
#define _DAC_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_2115983437_H
#define TOP_LEVEL_PREAMBLE_2115983437_H
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
} _dac_setvalue_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    _dac_setvalue_t* _lf_setvalue;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    // width of -2 indicates that it is not a multiport.
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    int _lf_setvalue_width;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    // Default input (in case it does not get connected)
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    _dac_setvalue_t _lf_default__setvalue;
    #line 34 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    reaction_t _lf__reaction_0;
    #line 39 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    trigger_t _lf__setvalue;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf"
    reaction_t* _lf__setvalue_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _dac_self_t;
_dac_self_t* new__dac();
#endif // _DAC_H
