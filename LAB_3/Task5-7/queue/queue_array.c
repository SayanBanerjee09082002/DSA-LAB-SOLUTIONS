#include "../element/element.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_SIZE 1000

struct Queue {
    int top;
    Element data[QUEUE_SIZE];
};

Queue *createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) 
        q->top = -1;
    return q;
}

bool enqueue(Queue *queue, Element element) {
    queue->data[++(queue->top)] = element;
    return true;
}

bool dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty");
        return false;
    }
    for (int i = 0; i < queue->top; i++)
        queue->data[i] = queue->data[i+1]; 
    (queue->top)--;
    return true;
}

Element *front(Queue *queue) {
    if (queue->top == -1)
        return NULL;
    else 
        return &(queue->data[0]);
}

int size(Queue *queue) {
    return (queue->top) + 1;
}

bool isEmpty(Queue *queue) {
    return queue->top == -1;
}

void freeQueue(Queue *queue) {
    free(queue);
}