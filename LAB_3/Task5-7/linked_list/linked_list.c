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
    if (list->count == 0)
        list->tail = node;
    list->head = node;
    node->next = temp;
    (list->count)++;
}

void removeLastNode(LIST list)
{
    NODE temp = list->head;
    while (temp->next->next != NULL)
        temp = temp->next;
    NODE temp2 = temp->next;
    temp->next = NULL;
    list->tail = temp;
    free(temp2);
}

void insertNodeAtEnd(NODE node, LIST list)
{
    NODE temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    list->tail = node;
    (list->count)++;
}