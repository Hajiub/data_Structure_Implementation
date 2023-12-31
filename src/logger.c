#include <time.h>
#include <string.h>
#include "logger.h" 

void logMessage(LogLevel level, const char *format, ...)
{

    time_t currentTime;
    time(&currentTime);
    char *timeString = ctime(&currentTime);
    timeString[strlen(timeString) - 1] = '\0';
    const char *levelString;
    
    switch(level)
    {
        case DEBUG:
            levelString = "DEBUG";
            break;
        case INFO:
            levelString = "INFO";
            break;
        case WARN:
            levelString = "WARN";
            break;
        case ERROR:
            levelString = "ERROR";
            break;
        default:
            break;
    }

    fprintf(stdout, "[%s] [%s] ", timeString, levelString);

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fprintf(stdout,"\n");
}
