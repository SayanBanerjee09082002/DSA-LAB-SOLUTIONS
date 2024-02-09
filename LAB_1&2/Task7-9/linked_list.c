#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;

struct node
{
    int ele;
    NODE next;
};

typedef struct linked_list *LIST;
struct linked_list
{
    int count;
    NODE head;
};

LIST createNewList()
{
    LIST myList;
    myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}

NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}

void insertAfter(int searchEle, NODE n1, LIST l1)
{
    if (l1->head == NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
        NODE temp = l1->head;
        NODE prev = temp;
        while (temp != NULL)
        {
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if (temp->next == NULL)
            {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}

void deleteAt(int searchEle, LIST l1)
{
    if (l1->head == NULL)
    {
        printf("No nodes in the linked list\n");
    }
    else
    {
        NODE temp = l1->head;
        NODE prev = temp;
        while (temp != NULL)
        {
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if (temp->next == NULL)
            {
                prev->next = NULL;
                free(temp);
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                l1->count--;
            }
            return;
        }
    }
}

void insertFirst(int searchEle, NODE n1, LIST l1)
{
    if (l1->head == NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
        n1->next = l1->head;
        l1->head = n1;
        l1->count++;
    }
    return;
}

void deleteFirst(int searchEle, LIST l1)
{
    if (l1->head == NULL)
    {
        printf("No nodes in the linked list\n");
    }
    else
    {
        NODE temp = l1->head;
        l1->head = l1->head->next;
        free(temp);
    }
    return;
}

int search(int searchEle, LIST l1)
{
    int index = 0;
    if (l1->head == NULL)
    {
        printf("No nodes in the linked list\n");
        return -1;
    }
    else
    {
        NODE temp = l1->head;
        while (temp->ele != searchEle || temp->next != NULL)
        {
            temp = temp->next;
            index++;
        }
        if (temp->next == NULL)
        {
            index = -1;
        }
    }
    return index;
}

void rotate(LIST l1, int k)
{
    if (l1->count <= k)
        printf("Not possible");
    else
    {
        NODE temp = l1->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = l1->head;
        int index = 1;
        temp = l1->head->next;
        NODE prev = l1->head;
        while (index != k)
        {
            temp = temp->next;
            prev = prev->next;
            index++;
        }
        l1->head = temp;
        prev->next = NULL;
    }
    return;
}

int hasCycle(LIST l1) {
    NODE tortoise = l1->head;
    NODE hare = l1->head;
    while (tortoise->next != NULL || hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare)
            return 1;
    }
    return 0;
}

void printList(LIST l1)
{
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

int main()
{
    // Create a new linked list
    LIST myLinkedList = createNewList();

    int choice, value, searchElement;

    do
    {
        printf("\n----- Menu -----\n");
        printf("1. Insert After\n");
        printf("2. Delete At\n");
        printf("3. Insert First\n");
        printf("4. Delete First\n");
        printf("5. Search\n");
        printf("6. Print List\n");
        printf("7. Rotate\n");
        printf("8. Has Cylce\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element after which to insert: ");
            scanf("%d", &searchElement);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertAfter(searchElement, createNewNode(value), myLinkedList);
            break;

        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &searchElement);
            deleteAt(searchElement, myLinkedList);
            break;

        case 3:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertFirst(0, createNewNode(value), myLinkedList);
            break;

        case 4:
            deleteFirst(0, myLinkedList);
            break;

        case 5:
            printf("Enter the element to search: ");
            scanf("%d", &searchElement);
            int index = search(searchElement, myLinkedList);
            if (index != -1)
                printf("Element %d found at index %d\n", searchElement, index);
            else
                printf("Element %d not found\n", searchElement);
            break;

        case 6:
            printf("Current Linked List:\n");
            printList(myLinkedList);
            break;

        case 7:
            printf("Enter the steps you want to go ahead: ");
            scanf("%d", &searchElement);
            rotate(myLinkedList, searchElement);
            break;
        
        case 8:
            printf("Has Cyle: %s", hasCycle(myLinkedList) ? "True" : "False");
            break;

        case 0:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 0);

    // Free allocated memory
    NODE current = myLinkedList->head;
    while (current != NULL)
    {
        NODE next = current->next;
        free(current);
        current = next;
    }
    free(myLinkedList);

    return 0;
}