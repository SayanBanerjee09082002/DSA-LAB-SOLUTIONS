#ifndef DELETION_H
#define DELETION_H

#include "../bst/bst.h"
#include "../query/query.h"

void delete(BST *bst, Node *node);
Node* removeHalfNodes(Node *node);

#endif