#include "logger.h"
#include <time.h>

int main()
{

	logger(LOG_INFO, "This is an info message.");
	logger(LOG_DEBUG, "This is a debug message.");
	logger(LOG_ERROR, "This is an error message.");
	logger(LOG_WARNING, "This is a warning message.");
	logger(LOG_IMERGENCY, "This is an imergency message.");
	logger(LOG_ALERT, "This is an alert message.");
	logger(LOG_CRITICAL, "This is a critical message.");


	return 0;
}
