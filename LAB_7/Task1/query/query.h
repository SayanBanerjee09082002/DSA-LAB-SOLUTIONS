#ifndef QUERY_H
#define QUERY_H

#include "../avl/avl.h"
#include <stdlib.h>

int height(struct node *node);
int get_balance_factor(struct node *node);
int max_of(int num1, int num2);
int is_AVL(struct node *root);

#endif