#ifndef ZIGBEE_CONTROLLER_H
#define ZIGBEE_CONTROLLER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    // Add private members as needed
    int dummy; // Placeholder, replace or remove as needed
} ZigbeeController;

/**
 * @brief 
 * 
 * @return ZigbeeController* 
 */
void zigbee_controller_init(ZigbeeController* controller);

/**
 * @brief 
 * 
 * @param controller 
 */
void zigbee_controller_destroy(ZigbeeController* controller);

/**
 * @brief 
 * 
 * @param controller 
 * @return true 
 * @return false 
 */
bool zigbee_controller_start(ZigbeeController* controller);

/**
 * @brief 
 * 
 * @param controller 
 */
void zigbee_controller_stop(ZigbeeController* controller);

/**
 * @brief 
 * 
 * @param controller 
 * @param data 
 * @param length 
 * @return true 
 * @return false 
 */
bool zigbee_controller_send_data(ZigbeeController* controller, const uint8_t* data, uint16_t length);

/**
 * @brief 
 * 
 * @param controller 
 * @param buffer 
 * @param buffer_size 
 * @return int 
 */
int zigbee_controller_receive_data(ZigbeeController* controller, uint8_t* buffer, uint16_t buffer_size);

/**
 * @brief 
 * 
 * @param controller 
 * @return true 
 * @return false 
 */
bool zigbee_controller_is_connected(const ZigbeeController* controller);

#endif // ZIGBEE_CONTROLLER_H