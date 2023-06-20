#pragma once

#include <sys/types.h>
#include "wd.h"

#define NO (void)

typedef struct
{
    int argc;
    const char **argv;
    time_t interval;
    size_t threshold;
}data_t;
