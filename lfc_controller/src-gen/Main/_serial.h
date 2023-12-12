#ifndef _SERIAL_H
#define _SERIAL_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1920321355_H
#define TOP_LEVEL_PREAMBLE_1920321355_H
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
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
} _serial_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint8_t* value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _serial_read_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    _serial_trigger_t* _lf_trigger;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    // width of -2 indicates that it is not a multiport.
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    int _lf_trigger_width;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    // Default input (in case it does not get connected)
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    _serial_trigger_t _lf_default__trigger;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    _serial_read_t _lf_read;
    #line 17 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    int _lf_read_width;
    #line 48 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    reaction_t _lf__reaction_0;
    #line 53 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    trigger_t _lf__trigger;
    #line 16 "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf"
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _serial_self_t;
_serial_self_t* new__serial();
#endif // _SERIAL_H
