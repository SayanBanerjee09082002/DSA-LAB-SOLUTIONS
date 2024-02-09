#include <stdlib.h>
#include "../element/element.h"
#include "linked_list.h"

LIST createNewList()
{
    LIST newList = malloc(sizeof(struct linked_list));
    newList->count = 0;
    return newList;
}

NODE createNewNode(Element data)
{
    NODE newNode = malloc(sizeof(struct node));
    newNode->data = data;
    return newNode;
}

void insertNewNode(NODE node, LIST list)
{
    NODE temp = list->head;
    list->head = node;
    node->next = temp;
    (list->count)++;
}

void removeFirstNode(LIST list)
{
    NODE temp = list->head;
    list->head = list->head->next;
    (list->count)--;
    free(temp);
}

void insertNodeAtEnd(NODE node, LIST list)
{
    NODE temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    (list->count)++;
}