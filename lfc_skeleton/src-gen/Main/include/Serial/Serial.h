#ifndef _serial_H
#define _serial_H
#ifndef TOP_LEVEL_PREAMBLE_1125509551_H
#define TOP_LEVEL_PREAMBLE_1125509551_H
/*Correspondence: Range: [(9, 2), (11, 18)) -> Range: [(0, 0), (2, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf)*/#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include <stdio.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct serial_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} serial_self_t;
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
} serial_trigger_t;
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
} serial_read_t;
#endif
