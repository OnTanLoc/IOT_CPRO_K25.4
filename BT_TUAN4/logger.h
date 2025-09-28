#include <stddef.h>

#ifndef LOGGER_H
#define LOGGER_H

//defind logger
#define LOG_IMERGENCY 0
#define LOG_ALERT 1
#define LOG_CRITICAL 2
#define LOG_ERROR 3
#define LOG_WARNING 4
#define LOG_NOTICE 5
#define LOG_INFO 6
#define LOG_DEBUG 7


void logger(int level, const char* message);

#endif
