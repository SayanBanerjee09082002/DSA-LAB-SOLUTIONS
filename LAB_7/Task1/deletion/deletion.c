#include "deletion.h"

Node *delete_AVL(Node *node, int value) {
     // Perform the normal BST rotation
    if (node == NULL)
        return(newNode(value));
 
    if (value < node->value)
        node->left  = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;
 
    //Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

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