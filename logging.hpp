typedef enum log_level_t
{
    LOG_CRITICAL = 0,
    LOG_ERROR = 1,
    LOG_WARNING = 2,
    LOG_INFO = 3,
    LOG_VERBOSE = 4
} log_level_t;

#define LOG_LEVEL LOG_INFO

// Emit color codes
#define LOG_USE_COLOR

void pretty_log(log_level_t log_level, const char *log_source, const char *fmt, ...);
