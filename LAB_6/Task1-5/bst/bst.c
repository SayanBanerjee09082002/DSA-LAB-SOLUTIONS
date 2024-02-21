#include "bst.h"

BST *new_bst()
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}