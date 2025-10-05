API :
1/ sensor_simaulate:
  	API random to simulate sensor value
	datatype: sensor_data_t
	return: 
		- moisture_data_percent: percent of soil moisture
		- temperature_data_celsius: temperature environment

        time_t time_landmark: save time standard to compair with time system
        time_t time_system: real time of system

2/ button_handler:
    API saved state of button state and button case, this API only run once when system load
	datatype: return_state_button_t
	return:
		- return_button_mode: choose mode AUTO/MANUAL
		- return_button_case_manual: if choose mode MANUAL, control pump ON/OFF

3/ watering_logic:
    handle system logic base on sensor
    data_type: int
    return: 
        - watering_flag: = 1: enough condition to turn on pump
                         = 0: moisture high, time out

4/ actuator:
	active simulate active peripheral, printf state of peripheral
	datatype: void


DATATYPE DEFINE:
    LED_display_regime_t: 4 state of led
        include: - LED_ERROR: LED red
	             - LED_WATERING: LED yellow
	             - LED_NOMAL: LED green
	             - LED_LOW_MOISTURE_ALERT: LED red

    mode_watering_t: mode of system
        include: - MODE_MANUAL: manual control base on pump_state 
                 - MODE_AUTO: handle base on watering_logic

    pump_state_t: state of pump when manual control
        include: - PUMP_ON: on pump manually
                 - PUMP_OFF: off pump manually

    sensor_data_t: structure signal from sensor transmit it will receive and handle by watering_logic.c
        include: - int moisture_data_percent: percentage moisture
	             - int temperature_data_celsius: temperature of environment unit celsius
	             - int time_present: result of time standard minus time of system