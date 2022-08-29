#include <stdarg.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "logging.hpp"


void pretty_log(log_level_t log_level, const char *log_source, const char *fmt, ...)
{
    // Newline included, emits nice readable logs to help with log level and source
    // TODO might need to handle concurrency someday
    // Example log
    // pretty_log(LOG_INFO, "Main", "Hello world, here's a number %d", 1203);
    //  41617ms [INFO] Main - Hello world, here's a number 1203\n

    // Emit time
    printf("%6lums ", to_ms_since_boot(get_absolute_time()));  // Left-pad to a length of 6.  1e6ms is about 17 minutes

    // Emit log_level
    printf("[");
    switch (log_level)
    {
        case LOG_VERBOSE:
            printf("VERBOSE");
            break;
        
        case LOG_INFO:
            printf("INFO");
            break;
        
        case LOG_WARNING:
            #ifdef LOG_USE_COLOR
            printf("\033[;33mWARNING\033[0m");  // Yellow
            #else
            printf("WARNING");
            #endif
            break;
        
        case LOG_ERROR:
            #ifdef LOG_USE_COLOR
            printf("\033[;31mERROR\033[0m");  // Red
            #else
            printf("ERROR");
            #endif
            break;
        
        case LOG_CRITICAL:
            #ifdef LOG_USE_COLOR
            printf("\033[1;35mCRITICAL\033[0m");  // Magenta bold
            #else
            printf("CRITICAL");
            #endif
            break;
        
        default:
            printf("UNKNOWN_LOG_LEVEL");  // Make it a little longer so it's obvious, but don't interrupt the logging otherwise
            break;
    }

    // Close log_level and emit log_source
    printf("] %s - ", log_source);

    // Emit the rest of the message
    va_list arg;
    va_start(arg, fmt);
    vprintf(fmt, arg);
    va_end(arg);

    // Finish with a newline
    printf("\n");
}
