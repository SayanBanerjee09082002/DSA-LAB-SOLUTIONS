#include "traversal.h"

void traverse_preorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d, ", node->value);
    traverse_preorder(node->left);
    traverse_preorder(node->right);
}

void traverse_inorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_inorder(node->left);
    printf("%d, ", node->value);
    traverse_inorder(node->right);
}

void traverse_postorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_postorder(node->left);
    traverse_postorder(node->right);
    printf("%d, ", node->value);
}