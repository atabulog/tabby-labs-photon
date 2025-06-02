#include "light_controller.h"
#include "driver/ledc.h"
#include "driver/gpio.h"

static light_controller_t light_controller = 
{
    .is_ready = false // Initialize the controller state
};

void light_controller_init()
{

    // Configure LEDC PWM for GPIO D0 (assume D0 is mapped to a valid GPIO number, e.g., GPIO_NUM_16)
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = LEDC_TIMER_8_BIT,
        .freq_hz          = 2500,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .gpio_num       = 23,
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = LEDC_CHANNEL_0,
        .timer_sel      = LEDC_TIMER_0,
        .duty           = 0, // Start with LED off
        .hpoint         = 0,
        .flags = { .output_invert = 0 }
    };
    ledc_channel_config(&ledc_channel);

    // Set initial duty and update
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 0);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
    light_controller.is_ready = true; // Mark the controller as ready
}

bool light_controller_is_ready()
{
    // Check if the LEDC is initialized and ready
    return light_controller.is_ready;
}

void light_controller_set_brightness(uint8_t red, uint8_t green, uint8_t blue, uint8_t warm_white, uint8_t cold_white)
{
    if (!light_controller.is_ready) {
        return; // Ensure the controller is initialized before setting brightness
    }

    // Set the duty cycle for each color channel
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, red);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, green);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, blue);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_3, warm_white);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_3);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_4, cold_white);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_4);
}
