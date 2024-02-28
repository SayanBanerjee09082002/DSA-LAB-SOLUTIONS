#include "query.h"

int height(struct node *node) 
{ 
    if (node == NULL) 
        return 0; 
    return node->height; 
}

int get_balance_factor(struct node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

int max_of(int num1, int num2) 
{ 
    return (num1 > num2) ? num1 : num2; 
} 

int is_AVL(struct node *root) {
    if (root == NULL)
        return 0;
    int lh = is_AVL(root->left);
    if (lh == -1)
        return -1;
    int rh = is_AVL(root->right);
    if (rh == -1)
        return -1;
 
    if (abs(lh - rh) > 1)
        return -1;
    else
        return lh > rh ? lh + 1 : rh + 1;
}