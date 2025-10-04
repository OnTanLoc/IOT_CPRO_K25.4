/*
    file name: button.c
    - function: check button cho choose state of system
    - peripheral: - button state to choose AUTO/MANUAL for system
                  - button in case manual to ON/OFF manually
    - logic: - choose state in button 1
             - case auto: use API of wattering_logic.c
             - case manual: 1 -> off pumb
                            2 -> on pumb
    - return: void
*/

#include <stdio.h>
#include "config.h"

return_state_button_t button_handler() {

    int input_button_mode = 0;
    int input_case_manual = 0;

    mode_watering_t watering_mode;
    pump_state_t pump_state_manual;

    do {
        printf("CHOOSE STATE FOR SYSTEM\n");
        printf("1.mode auto\n");
        printf("2.mode manual\n");

        scanf("%d", &input_button_mode);

        if (input_button_mode == 2) {
            watering_mode = MODE_MANUAL;

            printf("CHOOSE STATE FOR MODE MANUAL\n");
            printf("1.PUMP OFF\n");
            printf("2.PUMP ON (10s)\n");

            scanf("%d", &input_case_manual);

            if (input_case_manual == 1) {
                pump_state_manual = PUMP_OFF;
            } else if (input_case_manual == 2) {
                pump_state_manual = PUMP_ON;
            } else {
                printf ("false value");
            }

        } else if (input_button_mode == 1) { 
            watering_mode = MODE_AUTO; 
            pump_state_manual = PUMP_OFF;
        }

    } while (watering_mode == MODE_AUTO && 
            pump_state_manual == PUMP_ON && 
            pump_state_manual == PUMP_OFF );

    return_state_button_t button_return_value;
    button_return_value.return_button_case_manual = pump_state_manual;
    button_return_value.return_button_mode = watering_mode;

    printf("pump state manual %d \n", pump_state_manual);
    printf("watering mode %d \n", watering_mode);

    return button_return_value;
}