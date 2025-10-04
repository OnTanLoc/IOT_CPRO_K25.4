#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/* specification limit  of system */
#define MANUAL_WATERING_DURATION_SEC 10
#define CHECK_SENSOR_AFTER_SEC 300
#define MAX_MOISTURE_THRESHOLD 60 
#define MIN_MOISTURE_THRESHOLD 20
#define TEMPERATURE_CELSIUS_THRESHOLD 35
#define MINIMUN_MOISTURE 0
#define MAXIMUM_MOISTURE 100
#define AUTO_WATERING_DURATION_SEC 20
/* standard time of system hold landmark 0 */

typedef enum {
	LED_ERROR,/* LED red */
	LED_WATERING,/* LED yellow */
	LED_NOMAL,/* LED green */
	LED_LOW_MOISTURE_ALERT/* LED red */
} LED_display_regime_t;

typedef enum {
	MODE_AUTO,
	MODE_MANUAL
} mode_watering_t;

typedef enum {
	PUMP_OFF,
	PUMP_ON
} pump_state_t;

typedef struct {
	int moisture_data_percent;
	int temperature_data_celsius;
	int time_present;
} sensor_data_t;

/* state of 2 button to return value in button.c */
typedef struct {
    int return_button_mode;
	int return_button_case_manual;
} return_state_button_t;

/* 
  	API random to simulate sensor value
	datatype: sensor_data_t
	return: 
		- moisture_data_percent: percent of soil moisture
		- temperature_data_celsius: temperature environment
 */
sensor_data_t sensor_simulate(time_t *time_landmark, time_t time_system); 

/* 
	API saved state of button state and button case
	datatype: return_state_button_t
	return:
		- return_button_state: choose mode AUTO/MANUAL
		- return_button_case_manual: if choose mode MANUAL, control pump ON/OFF 
 */
return_state_button_t button_handler(); 

int watering_logic(time_t *time_landmark, int button_mode, int button_manual,time_t time_system);

