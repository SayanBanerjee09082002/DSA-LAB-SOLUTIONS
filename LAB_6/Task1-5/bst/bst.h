#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst
{
    Node *root;
} BST;

BST *new_bst();
Node *new_node(int value);

#endif