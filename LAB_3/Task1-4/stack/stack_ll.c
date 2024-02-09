#include "../element/element.h"
#include "../linked_list/linked_list.h"
#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

struct Stack {
    LIST list;
};

Stack *newStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;
    
    stack->list = createNewList();
    return stack;
}

bool push(Stack *stack, Element element) {
    NODE newNode = createNewNode(element);
    if (newNode == NULL)
        return false;
    
    insertNewNode(newNode, stack->list);
    return true;
}

Element *top(Stack *stack) {
    if (isEmpty(stack))
        return NULL;
    
    return &(stack->list->head->data);
}

bool pop(Stack *stack) {
    if (isEmpty(stack))
        return false;
    
    removeFirstNode(stack->list);
    return true;
}

bool isEmpty(Stack *stack) {
    return stack->list->count == 0;
}

void freeStack(Stack *stack) {
    while (!isEmpty(stack))
        pop(stack);
    
    free(stack->list);
    free(stack);
}