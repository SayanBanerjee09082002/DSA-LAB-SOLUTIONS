#include "rotation.h"

struct node *rotate_left(struct node *x)
{
    struct node *y = x->right; 
    struct node *beta = y->left; 
  
    y->left = x; 
    x->right = beta; 
  
    x->height = max_of(height(x->left), height(x->right)) + 1; 
    y->height = max_of(height(y->left), height(y->right)) + 1; 
  
    return y;
}

struct node *rotate_right(struct node *y) {
    struct node *x = y->left;
    struct node *beta = x->right; 
    
    x->right = y; 
    y->left = beta;

    y->height = max_of(height(y->left), height(y->right)) + 1; 
    x->height = max_of(height(x->left), height(x->right)) + 1;

    return x;
}