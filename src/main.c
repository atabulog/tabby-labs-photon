#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "light_controller.h"

static const char* TAG = "Main";

void setup()
{
    // Initialize the light controller
    light_controller_init();
    if (!light_controller_is_ready())
    {
        ESP_LOGE(TAG, "Failed to initialize command service");
        assert(false);
    }
}

void app_main()
{
    setup();

    uint8_t i = 0;
    int8_t increment = 5; // Increment value for brightness
    while(true)
    {
        // Set brightness for all channels
        //light_controller_set_brightness(i, i, i, i, i);
        i += increment;
        if(i == 255)
        {
            increment = -5; // Reverse direction when reaching max brightness
        }
        if (i == 0)
        {
            increment = 5; // Reverse direction when reaching min brightness
        }
        light_controller_set_brightness(i, i, i, i, i); // Set brightness for all channels
        ESP_LOGI(TAG, "duty cycle: %d", i);
        vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 10 milliseconds
    }
}