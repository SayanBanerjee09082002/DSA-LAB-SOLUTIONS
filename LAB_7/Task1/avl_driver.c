#include <stdio.h>
#include "avl/avl.h"
// #include "deletion/deletion.h"
#include "insertion/insertion.h"
#include "query/query.h"
#include "traversal/traversal.h"

int main()
{
    struct node *root = NULL;
    for (int i = 1; i <= 9; i++)
        root = insertAVL(root, i);

    printf("Is given BST avl: %s\n", is_AVL(root) > 0 ? "True" : "False");
}