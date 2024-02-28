#include <stdlib.h>
#include <stdio.h>
#include "../process/process.h"
#include "linked_list.h"

LIST createNewList()
{
    LIST newList = malloc(sizeof(struct linked_list));
    newList->count = 0;
    return newList;
}

NODE createNewNode(Process data)
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
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        (list->count)++;
    }
    else
    {
        NODE temp = list->head;
        list->head = node;
        list->head->next = temp;
        (list->count)++;
    }
}