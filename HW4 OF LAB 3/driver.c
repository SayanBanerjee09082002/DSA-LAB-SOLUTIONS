#include <stdio.h>
#include <stdlib.h>
#include "process/process.h"
#include "queue/queue.h"

Process itoe(int id, int time, int duration) {
    Process e;
    e.pid = id;
    e.arrival_time = time;
    e.burst_time = duration;
    return e;
}

int main() {
    FILE *file = fopen("fcfs.txt", "r");

    if (file == NULL)
        printf("MAA CHUDA .|.\n");
    
    int process_num;
    fscanf(file, "%d", &process_num);
    
    Queue *q = createQueue();

    for (int i = 1; i <= process_num; i++) {
        int a,b,c;
        fscanf(file, "%d %d %d", &a, &b, &c);
        enqueue(q, itoe(a,b,c));
    }
    
    int tick = 0;

    // for (int i = 0; i <= process_num; i++) {
    //     int value = front(q)->pid;
    //     printf("%d\n", front(q)->pid);
    //     if (i < 3)
    //         dequeue(q);
    // }

    for (int i = 1; i <= process_num; i++) {
        if (tick >= front(q)->arrival_time) {
            printf("PROCESS %d STARTED AT = %d\n", front(q)->pid, tick);
            printf("PROCESS %d ENDED AT = %d\n", front(q)->pid, tick + front(q)->burst_time);
            tick = tick + front(q)->burst_time;
            if (i < 5)
                dequeue(q);
        } else {
            tick = front(q)->arrival_time;
            printf("PROCESS %d STARTED AT = %d\n", front(q)->pid, tick);
            printf("PROCESS %d ENDED AT = %d\n", front(q)->pid, tick + front(q)->burst_time);
            tick = tick + front(q)->burst_time;
            if (i < 5)
                dequeue(q);
        }
    }

    // while (q != NULL) {
    //     if (tick >= front(q)->arrival_time) {
    //         printf("PROCESS %d STARTED AT = %d", front(q)->pid, tick);
    //         printf("PROCESS %d ENDED AT = %d", front(q)->pid, tick + front(q)->burst_time);
    //         dequeue(q);
    //     } else {
    //         tick = front(q)->arrival_time;
    //         printf("PROCESS %d STARTED AT = %d", front(q)->pid, tick);
    //         printf("PROCESS %d ENDED AT = %d", front(q)->pid, tick + front(q)->burst_time);
    //         dequeue(q);
    //     }
    // }
    
    return 0;
}