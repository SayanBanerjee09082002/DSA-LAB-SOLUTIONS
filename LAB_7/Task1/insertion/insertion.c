#include "insertion.h"

struct node *insertAVL(struct node *node, int value)
{
    //Normal BST insertion
    if (node == NULL)
        return (new_node(value));

    if (value < node->value)
        node->left = insertAVL(node->left, value);
    else if (value > node->value)
        node->right = insertAVL(node->right, value);
    else
        return node;
    
    //Updating height
    node->height = 1 + max_of(height(node->left), height(node->right));
    
    //Getting balance factor
    int balance_factor = get_balance_factor(node);

    // Left Left Case
    if (balance_factor > 1 && value < node->left->value)
        return rotate_right(node);

    // Right Right Case
    if (balance_factor < -1 && value > node->right->value)
        return rotate_left(node);

    // Left Right Case
    if (balance_factor > 1 && value > node->left->value)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Right Left Case
    if (balance_factor < -1 && value < node->right->value)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}