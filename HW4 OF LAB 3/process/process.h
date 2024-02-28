#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
};
typedef struct Process Process;

#endif