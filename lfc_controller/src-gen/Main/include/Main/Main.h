#ifndef _main_main_H
#define _main_main_H
#ifndef TOP_LEVEL_PREAMBLE_836782867_H
#define TOP_LEVEL_PREAMBLE_836782867_H
/*Correspondence: Range: [(9, 2), (10, 18)) -> Range: [(0, 0), (1, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/PID.lf)*/#include "stm32f4xx_hal.h"
#include <stdio.h>
/*Correspondence: Range: [(9, 2), (10, 18)) -> Range: [(0, 0), (1, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/DAC.lf)*/#include "stm32f4xx_hal.h"
#include <stdio.h>
/*Correspondence: Range: [(9, 4), (10, 18)) -> Range: [(0, 0), (1, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Encoder.lf)*/#include "stm32f4xx_hal.h"
#include <stdio.h>
/*Correspondence: Range: [(14, 2), (16, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf)*/#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct main_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int pos;
    int32_t encoder_count;
    int sign;
    int end[0]; // placeholder; MSVC does not compile empty structs
} main_self_t;
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
} main_force_triggered_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} qdec_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} qdec_read_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} dac_setvalue_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} pid_controller_current_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} pid_controller_target_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} pid_controller_out_t;
#endif
