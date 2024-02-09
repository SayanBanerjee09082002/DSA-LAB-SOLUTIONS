#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct student *Student;
typedef struct list *List;
struct timeval t1, t2;
double time_taken;

struct student
{
    char *id;
    float cgpa;
    Student next;
};

struct list
{
    Student head;
    int size;
};

typedef struct {
    Student *dynamic_array;
    int dynamic_array_size;
} Vector;

List init_list(void)
{
    List myList = (List)malloc(sizeof(struct list));
    myList->head = NULL;
    myList->size = 0;
    return myList;
}

Student create_node(char *id, float cgpa)
{
    Student node = (Student)malloc(sizeof(struct student));
    node->id = strdup(id);
    node->cgpa = cgpa;
    node->next = NULL;
    return node;
}

void insert_back(List list, Student node)
{
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        Student temp = list->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
    (list->size)++;
    return;
}

void read_file_linked_list(List studentList)
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char id[50];
    float cgpa;

    while (fscanf(file, "%[^,],%f", id, &cgpa) != EOF)
    {
        Student node = create_node(id, cgpa);
        insert_back(studentList, node);
    }
    
    fclose(file);
}

int read_file_dynamic_array(Vector* studentVector)
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char id[50];
    float cgpa;

    while (fscanf(file, "%[^,],%f", id, &cgpa) != EOF)
    {
        Student node = create_node(id, cgpa);
        studentVector->dynamic_array = realloc(studentVector->dynamic_array, (studentVector->dynamic_array_size + 1) * sizeof(struct student));
        studentVector->dynamic_array[(studentVector->dynamic_array_size)++] = node;
    }

    fclose(file);
    return studentVector->dynamic_array_size;
}

void insert_data_linked_list(char *id, float cgpa, int index, List studentList)
{
    if (index < 0 || index >= studentList->size)
    {
        printf("Invalid index\n");
        return;
    }

    if (index == 0)
    {
        Student newStudent = create_node(id, cgpa);
        newStudent->next = studentList->head;
        studentList->head = newStudent;
        return;
    }

    Student temp = studentList->head;

    if (index > 0)
        for (int i = 0; i < index - 1; i++)
        temp = temp->next;  
        
    Student temp2 = temp->next;
    temp->next = create_node(id, cgpa);
    temp = temp->next;
    temp->next = temp2;
}

int insert_data_dynamic_array(char *id, float cgpa, int index, Vector* studentVector)
{
    if (index < 0 || index >= studentVector->dynamic_array_size)
    {
        printf("Invalid index\n");
        return studentVector->dynamic_array_size;
    }

    studentVector->dynamic_array = realloc(studentVector->dynamic_array, (studentVector->dynamic_array_size + 1) * sizeof(Student));

    for (int i = studentVector->dynamic_array_size - 1; i >= index; i--)
        studentVector->dynamic_array[i + 1] = studentVector->dynamic_array[i];

    studentVector->dynamic_array[index] = create_node(id, cgpa);
    (studentVector->dynamic_array_size)++;
    return studentVector->dynamic_array_size;
}

void print_element_linked_list(List studentList, int index) {
    Student temp = studentList->head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    printf("%s, %f\n", temp->id, temp->cgpa);
}

void print_element_dynamic_array(Vector* studentVector, int index) {
    printf("%s, %f\n", studentVector->dynamic_array[index]->id, studentVector->dynamic_array[index]->cgpa);
}

void delete_linked_list(List studentList) {
    while (studentList->size > 0) {
        Student temp1 = studentList->head;
        Student temp2 = studentList->head->next;
        studentList->head = temp2;
        free(temp1);
        (studentList->size)--;
    }
}

void delete_dynamic_array(Vector* studentVector) {
    while (studentVector->dynamic_array_size > 0) {
        free(studentVector->dynamic_array[studentVector->dynamic_array_size - 1]);
        studentVector->dynamic_array = realloc(studentVector->dynamic_array, (studentVector->dynamic_array_size - 1) * sizeof(Student));
        (studentVector->dynamic_array_size)--;
    }
}

void main()
{
    List studentList = init_list();
    Vector studentVector;
    studentVector.dynamic_array = malloc(0);
    studentVector.dynamic_array_size = 0;

    // TIME FOR LINKED LIST
    gettimeofday(&t1, NULL);
    read_file_linked_list(studentList);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR LINKED LIST   = %f\n", time_taken);
    
    // TIME FOR DYNAMIC ARRARY
    gettimeofday(&t1, NULL);
    studentVector.dynamic_array_size = read_file_dynamic_array(&studentVector);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR DYNAMIC ARRAY = %f\n\n", time_taken);

    char* array_id[10];
    float array_cgpa[10];
    int array_index[10];
    for (int i = 0; i < 10; i++)
        array_id[i] = malloc(50 * sizeof(char));

    // Taking user input
    FILE *file = fopen("userinsert.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 10; i++)
        fscanf(file, "%[^,],%f,%d", array_id[i], &array_cgpa[i], &array_index[i]);
    fclose(file);

    // INSERTING IN LINKED LIST
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 10; i++)
        insert_data_linked_list(array_id[i], array_cgpa[i], array_index[i], studentList);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR INSERTION IN LINKED LIST = %f\n", time_taken);
    
    // INSERTING IN DYNAMIC ARRAY
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 10; i++)
        studentVector.dynamic_array_size = insert_data_dynamic_array(array_id[i], array_cgpa[i], array_index[i], &studentVector);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR INSERTION IN DYNAMIC ARRAY = %f\n\n", time_taken);

    int index = 503;

    //PRINTING FROM LINKED LIST
    gettimeofday(&t1, NULL);
    print_element_linked_list(studentList, index);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR PRINTING IN LINKED LIST = %f\n", time_taken);

    //PRINTING FROM DYNAMIC ARRAY
    gettimeofday(&t1, NULL);
    print_element_dynamic_array(&studentVector, index);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR PRINTING IN DYNAMIC ARRAY = %f\n\n\n", time_taken);

    //DELETING LINKED LIST
    gettimeofday(&t1, NULL);
    delete_linked_list(studentList);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR DELETING LINKED LIST = %f\n", time_taken);

    //DELETING DYNAMIC ARRAY
    gettimeofday(&t1, NULL);
    delete_dynamic_array(&studentVector);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR DELETING DYNAMIC ARRAY = %f\n\n", time_taken);

    free(studentList);
}
