#include "insertion.h"

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL)
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL)
    {
        if (value < current->value)
        {
            if (current->left == NULL)
            {
                current->left = node;
                break;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = node;
                break;
            }
            current = current->right;
        }
    }
}

BST* constructBST(int arr[], int size) {
    BST* bst = new_bst();
    if (size > 0) {
        bst->root = new_node(arr[0]);
        for (int i = 1; i < size; i++) {
            insert(bst, arr[i]);
        }
    }
    return bst;
}
