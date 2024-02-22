#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    int id;
    char name[32];
    int age;
    int height;
    int weight;
} Person;

typedef struct node {
    Person *data;
    int height;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() {
    BST *bst = malloc(sizeof(BST));
    if (bst != NULL)
        bst->root = NULL;
    return bst;
}

Node *new_node(Person *person) {
    Node *node = malloc(sizeof(Node));
    if (node != NULL) {
        node->data = person;
        node->height = person->height;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void insert(BST *bst, Person *person) {
    Node *node = new_node(person);
    if (bst->root == NULL) {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) {
        if (person->height < current->height) {
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

BST *constructBST(Person array[], int size) {
    BST *bst = new_bst();
    if (size > 0) {
        bst->root = new_node(&array[0]);
        for (int i = 1; i < size; i++) {
            insert(bst, &array[i]);
        }
    }
    return bst;
}

Node *LCA_helper(Node *node, int height1, int height2) {
    if (node == NULL)
        return NULL;

    if (node->height > height1 && node->height > height2)
        LCA_helper(node->left, height1, height2);

    if (node->height < height1 && node->height < height2)
        LCA_helper(node->right, height1, height2);

    return node;
}

Node *LCA(BST *bst, int id1, int id2) {
    return LCA_helper(bst->root, id1, id2);
}

int main() {
    FILE *file = fopen("dat10.csv", "r");
    if (file == NULL) {
        printf("Unable to open dat10.csv");
        return 1;
    }

    Person personArray[10];
    int index = 0;

    while (index < 10 && fscanf(file, "%d,%[^,],%d,%d,%d", &personArray[index].id, personArray[index].name, &personArray[index].age, &personArray[index].weight, &personArray[index].height) == 5)
        index++;

    BST *bst = constructBST(personArray, index);

    printf("Common Ancestor of keys 240 and 246 = %d\n", LCA(bst, 240, 246)->height);

    return 0;
}
