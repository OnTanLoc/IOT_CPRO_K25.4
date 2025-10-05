/*
    file name: sensor.c
    - function: create API simulate heat and moisture
    - peripheral: - heat sensor
                  - moisture sensor
                  - timer
    - logic: random 0 - 40 and 0 - 100 to simulate value received from sensor
    - return: data_receiced (data type: sensor_data_t)
*/

#include <stdio.h>
#include "config.h"
#include <stdlib.h>
#include <time.h>

data_to_handle_t sensor_simulate(time_t *time_landmark, time_t time_system) {
    srand(time_system);

    int time_elapse = time_system - *time_landmark; /* time_elasp: standard time from system run */

    data_to_handle_t data_received;
    data_received.sensor_data.temperature_data_celsius = rand() % ((40 + 1) - 0); 
    data_received.sensor_data.moisture_data_percent = rand() % ((MAXIMUM_MOISTURE + 1) - MINIMUN_MOISTURE);
    data_received.sensor_data.time_present = time_elapse;

    int heat_temp = data_received.sensor_data.temperature_data_celsius;
    int mois_temp = data_received.sensor_data.moisture_data_percent;
    
    return data_received;
}