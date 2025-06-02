#ifndef LIGHT_CONTROLLER_H
#define LIGHT_CONTROLLER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    bool is_ready; // track initialization state
}light_controller_t;

void light_controller_init();

bool light_controller_is_ready();

void light_controller_set_brightness(uint8_t red, uint8_t green, uint8_t blue, uint8_t warm_white, uint8_t cold_white);


#endif // LIGHT_CONTROLLER_H