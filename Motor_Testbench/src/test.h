// #ifndef TEST_H
// #define TEST_H

#include <zephyr.h>
#include "motor.h"
#include "encoder.h"

void setupTests();
void runTest(double freq);
void runRiseTest(double speed);
void runForceTest(double freq, int mag);

void printVals(double degree, double target, uint64_t time, double freq, double mag, uint64_t maxtime, double speed);
uint64_t determineSimTime(double freq);

// #endif