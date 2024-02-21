#include "deletion.h"

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        Node *current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    if (node->left == NULL)
    {
        Node *current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    if (node->right == NULL)
    {
        Node *current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    Node *temp = successor(node);
    node->value = temp->value;
    delete (bst, temp);
    return;
}

Node* removeHalfNodes(Node *node) {
    if (node == NULL) {
        return NULL;
    }
    node->left = removeHalfNodes(node->left);
    node->right = removeHalfNodes(node->right);
    
    if (node->left == NULL && node->right != NULL) {
        Node* temp = node->right;
        free(node);
        return temp;
    }
    if (node->right == NULL && node->left != NULL) {
        Node* temp = node->left;
        free(node);
        return temp;
    }
    return node;
}