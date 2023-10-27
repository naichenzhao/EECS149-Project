#ifndef _main_main_H
#define _main_main_H
#ifndef TOP_LEVEL_PREAMBLE_42158278_H
#define TOP_LEVEL_PREAMBLE_42158278_H
/*Correspondence: Range: [(10, 2), (12, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src/Main.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
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
    int end[0]; // placeholder; MSVC does not compile empty structs
} main_self_t;
#endif
