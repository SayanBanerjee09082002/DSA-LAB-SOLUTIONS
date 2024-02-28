#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value; 
    struct node *left; 
    struct node *right; 
    int height;
} Node;

Node *new_node(int value);

#endif