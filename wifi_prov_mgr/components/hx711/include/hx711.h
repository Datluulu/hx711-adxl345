#ifndef hx711_H
#define hx711_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"
#include "driver/gpio.h"


typedef enum {
    eGAIN_128 = 1,
    eGAIN_64 = 3,
    eGAIN_32 = 2
} hx711_GAIN;

void hx711_init(gpio_num_t dout, gpio_num_t pd_sck, hx711_GAIN gain);
bool hx711_is_ready();
void hx711_set_gain(hx711_GAIN gain);
unsigned long hx711_read();
unsigned long hx711_read_average(char times);
unsigned long hx711_get_value(char times);
float hx711_get_units(char times);
void hx711_tare();
void hx711_set_scale(float scale);
float hx711_get_scale();
void hx711_set_offset(unsigned long offset);
unsigned long hx711_get_offset();
void hx711_power_down();
void hx711_power_up();

#endif // hx711_H
