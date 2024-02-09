#include "stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval t1, t2;
double time_taken;

Element itoe(int i, float f)
{
    Element e;
    e.int_value = i;
    e.float_value = f;
    return e;
}

void performance_small_csv()
{
    Stack *s = newStack();

    FILE *file = fopen("csv_files/small.csv", "r");
    if (file == NULL)
        printf("Unable to to open small.csv");

    int *score = calloc(100, sizeof(int));
    float *cg = calloc(100, sizeof(float));
    int index = 0;

    while (fscanf(file, "%d,%f", &score[index], &cg[index]) != EOF)
        index++;

    // Push function
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 100; i++)
    {
        push(s, itoe(score[i], cg[i]));
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR PUSH OPERATIONS = %f\n", time_taken);

    // Pop function
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 50; i++)
    {
        pop(s);
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR POP OPERATIONS = %f\n", time_taken);

    free(score);
    free(cg);
}

void performance_medium_csv()
{
    Stack *s = newStack();

    if (isEmpty(s))
        printf("Stack is empty\n");

    FILE *file = fopen("csv_files/medium.csv", "r");

    if (file == NULL)
        printf("Unable to to open medium.csv");

    int *score = calloc(500, sizeof(int));
    float *cg = calloc(500, sizeof(float));
    int index = 0;

    while (fscanf(file, "%d,%f", &score[index], &cg[index]) != EOF)
        index++;

    // Push function
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 500; i++)
    {
        push(s, itoe(score[i], cg[i]));
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR PUSH OPERATIONS = %f\n", time_taken);

    // Pop function
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 250; i++)
    {
        pop(s);
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR POP OPERATIONS = %f\n", time_taken);

    free(score);
    free(cg);
}

void performance_large_csv()
{
    Stack *s = newStack();

    if (isEmpty(s))
        printf("Stack is empty\n");

    FILE *file = fopen("csv_files/large.csv", "r");

    if (file == NULL)
        printf("Unable to to open large.csv");

    int *score = calloc(1000, sizeof(int));
    float *cg = calloc(1000, sizeof(float));
    int index = 0;

    while (fscanf(file, "%d,%f", &score[index], &cg[index]) != EOF)
        index++;

    // Push function
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 1000; i++)
    {
        push(s, itoe(score[i], cg[i]));
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR PUSH OPERATIONS = %f\n", time_taken);

    // Pop function
    gettimeofday(&t1, NULL);
    for (int i = 0; i < 500; i++)
    {
        pop(s);
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR POP OPERATIONS = %f\n", time_taken);

    free(score);
    free(cg);
}

int main()
{
    printf("\n\n\nPERFORMANCE OF STACK WITH LINKED LIST\n");
    printf("\nPERFORMANCE FOR SMALL CSV\n");
    performance_small_csv();
    printf("\nPERFORMANCE FOR MEDIUM CSV\n");
    performance_medium_csv();
    printf("\nPERFORMANCE FOR LARGE CSV\n");
    performance_large_csv();

    return 0;
}