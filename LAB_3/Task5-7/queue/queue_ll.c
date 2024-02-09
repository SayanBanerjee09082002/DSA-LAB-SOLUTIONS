#include "../element/element.h"
#include "../linked_list/linked_list.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct Queue {
    LIST list;
};

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->list = createNewList();
    }
    return q;
}

bool enqueue(Queue* queue, Element element) {
    NODE newNode = createNewNode(element);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }
    insertNodeAtEnd(newNode, queue->list);
    return true;
}

bool dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return false;
    }
    removeLastNode(queue->list);
    return true;
}

Element* front(Queue* queue) {
    return &(queue->list->tail->data);
}

int size(Queue* queue) {
    return queue->list->count;
}

bool isEmpty(Queue* queue) {
    return queue->list->count == 0;
}

void freeQueue(Queue* queue) {
    free(queue->list);
    free(queue);
}