#include <stdio.h>
#include "config.h"
#include <string.h>
#include <stdlib.h>

void actuator(data_to_handle_t logic_handle) {
    if (logic_handle.watering_flag == 1) {
        printf("[SYSTEM] ON \n");
    } else printf("[SYSTEM] OFF \n");

    LED_display_regime_t LED_display_present;

    int sensor_moisture = (int) logic_handle.sensor_data.moisture_data_percent;
    int sensor_temp = (int) logic_handle.sensor_data.temperature_data_celsius;
    int sensor_time = (int) logic_handle.sensor_data.time_present;
    bool watering_logic = (bool) logic_handle.watering_flag;

    if (sensor_moisture >= 0 && sensor_temp >= 0 && sensor_time >= 0 && watering_logic == 0) {
        LED_display_present = LED_NOMAL;

    } else if (sensor_moisture < MIN_MOISTURE_THRESHOLD) {
        LED_display_present = LED_LOW_MOISTURE_ALERT;

    } else if (watering_logic == 1) {
        LED_display_present = LED_WATERING;

    } else LED_display_present = LED_ERROR; 

    char *LED_ptr = (char*) malloc (30 * sizeof(LED_ptr)); 
    if(LED_ptr == NULL) {
        printf("[STATE] lack storage \n");
    }

    switch(LED_display_present) {
        case LED_NOMAL:
            strcpy(LED_ptr, "LED NORMAL");
            break;

        case LED_WATERING:
            strcpy(LED_ptr, "LED WARTERING");
            break;

        case LED_ERROR:
            strcpy(LED_ptr, "LED ERROR");
            break;

        case LED_LOW_MOISTURE_ALERT:
            strcpy(LED_ptr, "LED_LOW_MOISTURE_ALERT");
            break;
    }


    if (watering_logic == 1) printf("[STATE] PUMP: ON \n");
    else printf("[STATE] PUMP: OFF \n");

    printf("[STATE] TEMPERATURE: %d \t", sensor_temp);
    printf("[STATE] MOISTURE: %d \t",sensor_moisture);
    printf("[STATE] TIME: %d \n", sensor_time);
    printf("[STATE] LED: %s \n", LED_ptr);
    printf("\n");
    
    free(LED_ptr);
}