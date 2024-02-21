#include "query.h"

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL)
    {
        if (key == current->value)
        {
            return 1;
        }
        else if (key < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

int checkRight(Node *node, int val)
{
    if (node == NULL)
    {
        return 1;
    }
    if (node->value < val)
        return 0;
    return checkRight(node->left, val) && checkRight(node->right, val);
}

int checkLeft(Node *node, int val)
{
    if (node == NULL)
    {
        return 1;
    }
    if (node->value > val)
        return 0;
    return checkLeft(node->left, val) && checkLeft(node->right, val);
}

int is_valid_bst(Node *node)
{
    if (node == NULL)
        return 1;

    if (checkLeft(node->left, node->value) == 0 || checkRight(node->right, node->value) == 0)
        return 0;

    if (is_valid_bst(node->left) == 0 || is_valid_bst(node->right) == 0)
        return 0;

    return 1;
}

int find_height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_depth = find_height(node->left);
        int right_depth = find_height(node->right);

        if (left_depth > right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }
}
