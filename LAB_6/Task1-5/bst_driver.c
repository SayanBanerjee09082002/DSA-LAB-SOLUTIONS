#include <stdio.h>
#include "bst/bst.h"
#include "deletion/deletion.h"
#include "insertion/insertion.h"
#include "query/query.h"
#include "traversal/traversal.h"

void valid_bst_checker() {
    BST *bst = new_bst();
    insert(bst, 3);
    bst->root->left = new_node(2);
    bst->root->right = new_node(5);
    bst->root->left->left = new_node(1);
    bst->root->left->right = new_node(4);
    printf("Is valid BST : %s\n", is_valid_bst(bst->root) == 0 ? "False" : "True");
}

int main()
{   
    //BST CONSTRUCTION
    BST *bst = new_bst();
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 4);
    insert(bst, 5);
    insert(bst, 6);
    insert(bst, 7);
    insert(bst, 8);

    //TASK 1
    printf("Pre-order traversal  : ");
    traverse_preorder(bst->root);
    printf("\nIn-order traversal   : ");
    traverse_inorder(bst->root);
    printf("\nPost-order traversal : ");
    traverse_postorder(bst->root);

    //TASK 2
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    BST* newbst = constructBST(array, sizeof(array) / sizeof(array[0]));

    //TASK 3
    printf("\n");
    valid_bst_checker();

    //TASK 4
    printf("Height of new BST = %d\n", find_height(newbst->root));

    //TASK 5
    removeHalfNodes(newbst->root);

    return 0;
}