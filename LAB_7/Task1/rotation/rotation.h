#ifndef ROTATION_H
#define ROTATION_H

#include "../avl/avl.h"
#include "../query/query.h"

struct node *rotate_left(struct node *x);
struct node *rotate_right(struct node *x);

#endif