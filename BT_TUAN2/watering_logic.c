/*
    file name: watering_logic.c
    - function: control led base on sensor, counting timer
    - logic: green: - OFF, read sensor
                    - moisture bigger than threshold
             red: - sensor value error
                  - moisture alert
             yellow: - moisture not enough
                     - time out
*/

#include <stdio.h>
#include "config.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

/*
    watering_flag = 0 is turn off watering function
    watering_flag = 1 is on off watering function
 */

    bool watering_flag = 0;
    bool timer_flag = 0;

bool SPWS_RunFlag() {
    if (timer_flag = 1) {
        watering_flag = 1;
    } else watering_flag = 0;
    
    return watering_flag;    
}

bool timer(int read_time, int time_duaration) {
    if (read_time < time_duaration) {
            timer_flag = 1;
    } else timer_flag = 0;
        
    return timer_flag;
}

data_to_handle_t watering_logic(time_t *time_landmark, int button_mode, int button_manual, time_t time_system) {
    time_system = time(NULL);
    
    //sensor_data_t sensor_simulate();
    data_to_handle_t read_data_sensor = sensor_simulate(& *time_landmark, time_system);

    int time_duration = 0;
    int read_temp = read_data_sensor.sensor_data.temperature_data_celsius;
    int read_mois = read_data_sensor.sensor_data.moisture_data_percent;
    int read_time = read_data_sensor.sensor_data.time_present;
    bool watering_flag_return = 0;
    bool timer_flag_return = 0;

    if (button_mode == MODE_AUTO) { 
        if (read_mois < MIN_MOISTURE_THRESHOLD) {
            *time_landmark = time(NULL); /* reset timer */

            timer_flag_return = timer(read_time, AUTO_WATERING_DURATION_SEC);
            watering_flag_return = SPWS_RunFlag();
        } else if (read_mois >= MAX_MOISTURE_THRESHOLD) {
            timer_flag_return = 0;
            watering_flag_return = timer_flag_return;
        }
        
    } else if (button_mode == MODE_MANUAL) {
        if (button_manual == PUMP_ON) {
            *time_landmark = time(NULL);

            bool timer_flag_return = timer(read_time, MANUAL_WATERING_DURATION_SEC);
            watering_flag_return = timer_flag_return;
        } else watering_flag_return = 0;
    }

    printf("\n");
    printf("READ VALUE \n");
    printf("[READ]STATE %s \n", button_mode == 0 ? "MODE AUTO" : "MODE MANUAL");
    printf("[READ] TEMPERATURE: %d \t", read_temp);
    printf("[READ] MOISTURE: %d \t", read_mois);
    printf("[READ] TIME ELAPSE: %d \n", read_time);
    printf("[READ] WATERING FLAG: %d \n", watering_flag_return);
    printf("[READ] TIME FLAG: %d \n", timer_flag_return);
    printf("\n");

    watering_flag_return = read_data_sensor.watering_flag;

    data_to_handle_t logic_handle = read_data_sensor;

    return logic_handle;
}