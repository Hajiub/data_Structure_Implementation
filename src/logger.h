#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

typedef enum {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    
} LogLevel;

void logMessage(LogLevel level, const char *format, ...);
#endif
