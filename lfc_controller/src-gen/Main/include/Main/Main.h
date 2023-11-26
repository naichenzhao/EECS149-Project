#ifndef _main_main_H
#define _main_main_H
#ifndef TOP_LEVEL_PREAMBLE_678801430_H
#define TOP_LEVEL_PREAMBLE_678801430_H
/*Correspondence: Range: [(11, 2), (16, 27)) -> Range: [(0, 0), (5, 27)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf)*/#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"

#define LD5_Pin GPIO_PIN_5
#define LD5_GPIO_Port GPIOA
/*Correspondence: Range: [(9, 2), (11, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/lib/Serial.lf)*/#include <stdio.h>
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
    int counter;
    int sign;
    uint8_t* curr;
    int end[0]; // placeholder; MSVC does not compile empty structs
} main_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} serial_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint8_t* value;

} serial_read_t;
#endif
