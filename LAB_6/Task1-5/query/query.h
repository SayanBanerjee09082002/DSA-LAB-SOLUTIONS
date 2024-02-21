#include <stdlib.h>
#include "../bst/bst.h"

int search(BST *bst, int key);
int find_min(BST *bst);
int find_max(BST *bst);
Node *predecessor(Node *node);
Node *successor(Node *node);
int is_valid_bst(Node *node);
int find_height(Node *node);