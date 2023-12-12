#ifndef QDEC_H
#define QDEC_H

#include <zephyr.h>
#include <math.h>

double read_deg(void);
void reset_deg();
int check_count(uint32_t curr, uint32_t last);

#endif