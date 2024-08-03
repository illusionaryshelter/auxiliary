#ifndef _AUX_LOG__H_
#define _AUX_LOG__H_

#include "aconfig.h"
#include <stdio.h>
#include <inttypes.h>
#include "aif.h"


#ifndef AUX_LOG_ENABLE
#define AUX_LOG_ENABLE 0
#endif

#define ANSI_FG_BLACK "\33[1;30m"
#define ANSI_FG_RED "\33[1;31m"
#define ANSI_FG_GREEN "\33[1;32m"
#define ANSI_FG_YELLOW "\33[1;33m"
#define ANSI_FG_BLUE "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN "\33[1;36m"
#define ANSI_FG_WHITE "\33[1;37m"
#define ANSI_BG_BLACK "\33[1;40m"
#define ANSI_BG_RED "\33[1;41m"
#define ANSI_BG_GREEN "\33[1;42m"
#define ANSI_BG_YELLOW "\33[1;43m"
#define ANSI_BG_BLUE "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;35m"
#define ANSI_BG_CYAN "\33[1;46m"
#define ANSI_BG_WHITE "\33[1;47m"
#define ANSI_NONE "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define AUX_Log(format, ...)                                \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
         __FILE__, __LINE__, __func__, ##__VA_ARGS__);      \
    _Write("[%s:%d %s] " format "\n",                       \
           __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define _Log(...) do { printf(__VA_ARGS__); } while (0)

#define _Write(...) \
    AUX_IF(AUX_LOG_ENABLE, do { AUX_Log_write(__VA_ARGS__); } while (0), AUX_EMPTY)

#define AUX_Log_write(...)                \
    do                                    \
    {                                     \
        extern FILE *log_fp;              \
        if (log_fp != NULL)               \
        {                                 \
            fprintf(log_fp, __VA_ARGS__); \
            fflush(log_fp);               \
        }                                 \
    } while (0)

#if AUX_LOG_ENABLE
FILE *log_fp = NULL;
void init_log(const char *log_file)
{
    log_fp = stdout;
    if (log_file != NULL)
    {
        FILE *fp = fopen(log_file, "w");
        log_fp = fp;
    }
    AUX_Log("Log is written to %s", log_file ? log_file : "stdout");
}
#else
void init_log(const char *log_file){}
#endif

#endif