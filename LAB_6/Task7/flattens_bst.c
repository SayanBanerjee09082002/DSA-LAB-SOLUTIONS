#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

typedef struct lnode {
    int value;
    struct lnode *next;
} LNode;

typedef struct list {
    LNode *head;
    int count;
} List;

BST *new_bst() {
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

List *new_list() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

Node *new_node(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

LNode *new_lnode(int value) {
    LNode *node = malloc(sizeof(LNode));
    node->value = value;
    node->next = NULL;
    return node;
}

void insert(BST *bst, int value) {
    Node *node = new_node(value);
    if (bst->root == NULL) {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = node;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = node;
                break;
            }
            current = current->right;
        }
    }
}

BST* constructBST(int arr[], int size) {
    BST* bst = new_bst();
    if (size > 0) {
        bst->root = new_node(arr[0]);
        for (int i = 1; i < size; i++) {
            insert(bst, arr[i]);
        }
    }
    return bst;
}

void flattener_helper(Node *node, List *list) {
    if (node == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = new_lnode(node->value);
        list->count++;
    } else {
        LNode *temp = list->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_lnode(node->value);
        list->count++;
    }

    flattener_helper(node->left, list);
    flattener_helper(node->right, list);
}

List *flattener(BST *bst) {
    List *list = new_list();
    flattener_helper(bst->root, list);
    return list;
}

int main() {
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    BST *newbst = constructBST(array, sizeof(array) / sizeof(array[0]));

    List *list = flattener(newbst);

    return 0;
}
