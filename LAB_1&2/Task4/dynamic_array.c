#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 32

//String struct (just for encapsulation)
typedef struct {
    char string[MAX_STRING_LENGTH];
} String;

//Dynamic array storing the array and size of array. Named Vector
typedef struct {
    String* array;
    int size;
} Vector;


void init(Vector* vector) {
    //Initializing array to null as nothing is stored initially
    vector->array = NULL;
    //Size will be zero initially
    vector->size = 0;
}

void push_back(Vector* vector, char* string) {
    //Allocating more memmory to dynamic array to sotre new string
    vector->array = (String*)realloc(vector->array, (vector->size + 1) * sizeof(String));
    //Copying new string at the end of array
    strcpy(vector->array[vector->size].string, string);
    //Incrementing size by one
    (vector->size)++;
}

void push_start(Vector* vector, char* string) {
    //Allocating more memmory to dynamic array to sotre new string
    vector->array = (String*)realloc(vector->array, (vector->size + 1) * sizeof(String));
    // Shifting existing elements to make room for the new string at the start
    for (int i = vector->size; i > 0; i--)
        strcpy(vector->array[i].string, vector->array[i - 1].string);
    // Copying the new string at the start of the array
    strcpy(vector->array[0].string, string);
    //Incrementing size by one
    (vector->size)++;
}

void delete_index(Vector* vector, int index) {
    //Copying all elements after the given index to one index before
    for (int i = index; i < vector->size - 1; i++)
        strcpy(vector->array[i].string, vector->array[i+1].string);
    //Reducing consumed memory by one'
    vector->array = (String*)realloc(vector->array, (vector->size - 1) * sizeof(String));
    //Decrementing size by one
    (vector->size)--;
}

int return_length(Vector* vector) {
    return vector->size;
}

void print_vector(Vector* vector) {
    printf("Size = %d\nContents: ", vector->size);
    for (int i = 0; i < vector->size; i++)
        printf("%s, ", vector->array[i].string);
}

int main() {
    Vector dynamic_array;
    char response = 'y';

    init(&dynamic_array);

    while (response == 'y' || response == 'Y') {
        printf("\nChose the option:\n1. Add string at the end of the array\n2. Add string at the beginning of the array\n3. Delete an element at index 'x'\n4. Display the length of array\n5. Display all elements\n");
        scanf(" %c", &response);

        switch (response) {
            case '1': {
                char newString[MAX_STRING_LENGTH];
                printf("Enter a string to add to the end: ");
                scanf("%s", newString);
                push_back(&dynamic_array, newString);
                break;
            }
            case '2': {
                char newString[MAX_STRING_LENGTH];
                printf("Enter a string to add to the end: ");
                scanf("%s", newString);
                push_start(&dynamic_array, newString);
                break;
            }
            case '3': {
                int index;
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                delete_index(&dynamic_array, index);
                break;
            }
            case '4':
                printf("Length of vector = %d", return_length(&dynamic_array));
                break;
            case '5':
                print_vector(&dynamic_array);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("\nContinue?\n");
        scanf(" %c", &response);
    }

    free(dynamic_array.array);

    return 0;
}