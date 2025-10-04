#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "config.h"

time_t time_system = 0;

void main() {
    
    return_state_button_t read_button = button_handler();
    int button_manual = read_button.return_button_case_manual;
    int button_mode = read_button.return_button_mode;

    time_t time_landmark = time(NULL);

    while (1)
    {
        watering_logic (&time_landmark, button_mode, button_manual, time_system);
        sleep(0.1);
    }
    
}