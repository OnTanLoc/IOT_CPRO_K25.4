#include "logger.h"
#include <stdio.h>
#include <time.h>

//return 7 loga_level
const char* convert_log_state(int level) {
	switch (level) {
	case LOG_INFO:
		return "INFO";

	case LOG_DEBUG:
		return "DEBUG";

	case LOG_ERROR:
		return "ERROR";

	case LOG_WARNING:
		return "WARNNING";

	case LOG_IMERGENCY:
		return "IMERGENCY";

	case LOG_ALERT:
		return "ALERT";

	case LOG_CRITICAL:
		return "CRITICAL";

	default:
		return "Unknown State";
	}
}

void logger(int level, const char* message) {
    if (level < LOG_ERROR) {
        return;//when level < log level -> by pass
    }

    //get time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%YYYY-%mm-%d %HH:%MM:%S", t);

    // print log
    printf("[%s] [%s] %s\n", time_buf, convert_log_state(level), message);
}
