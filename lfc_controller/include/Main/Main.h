#ifndef _main_main_H
#define _main_main_H
#ifndef TOP_LEVEL_PREAMBLE_1881218633_H
#define TOP_LEVEL_PREAMBLE_1881218633_H
/*Correspondence: Range: [(10, 2), (15, 27)) -> Range: [(0, 0), (5, 27)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf)*/#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"

#define LD5_Pin GPIO_PIN_5
#define LD5_GPIO_Port GPIOA
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
    int end[0]; // placeholder; MSVC does not compile empty structs
} main_self_t;
#endif
