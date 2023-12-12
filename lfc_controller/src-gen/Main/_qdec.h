#ifndef _QDEC_H
#define _QDEC_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_204568533_H
#define TOP_LEVEL_PREAMBLE_204568533_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
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
} _qdec_trigger_t;
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
} _qdec_read_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    _qdec_trigger_t* _lf_trigger;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    // width of -2 indicates that it is not a multiport.
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    int _lf_trigger_width;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    // Default input (in case it does not get connected)
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    _qdec_trigger_t _lf_default__trigger;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    _qdec_read_t _lf_read;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    int _lf_read_width;
    #line 51 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    reaction_t _lf__reaction_0;
    #line 56 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    trigger_t _lf__trigger;
    #line 15 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf"
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _qdec_self_t;
_qdec_self_t* new__qdec();
#endif // _QDEC_H
