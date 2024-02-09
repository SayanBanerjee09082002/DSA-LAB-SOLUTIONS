#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "insertion_sort/insertion_sort.h"
#include "structure/person.h"

float size[] = {1000, 10000, 100000, 1000000, 7578440};
float time[5];
struct timeval t1, t2;
double time_taken;

void sort_dat1000()
{
    FILE *file = fopen("csv_files/dat1000.csv", "r");
    if (file == NULL)
        printf("Unable to to open dat1000.csv");

    Person *personArray = calloc(1000, sizeof(Person));
    int index = 0;

    while (fscanf(file, "%d,%[^,],%d,%d,%d", &personArray[index].id, personArray[index].name, &personArray[index].age, &personArray[index].weight, &personArray[index].height) != EOF)
        index++;

    gettimeofday(&t1, NULL);
    insertion_sort(personArray, 1000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN TO SORT 1000 ELEMENTS = %f\n", time_taken);
    time[0] = time_taken;
}

void sort_dat10000()
{
    FILE *file = fopen("csv_files/dat10000.csv", "r");
    if (file == NULL)
        printf("Unable to to open dat10000.csv");

    Person *personArray = calloc(10000, sizeof(Person));
    int index = 0;

    while (fscanf(file, "%d,%[^,],%d,%d,%d", &personArray[index].id, personArray[index].name, &personArray[index].age, &personArray[index].weight, &personArray[index].height) != EOF)
        index++;

    gettimeofday(&t1, NULL);
    insertion_sort(personArray, 10000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN TO SORT 10000 ELEMENTS = %f\n", time_taken);
    time[1] = time_taken;
}

void sort_dat100000()
{
    FILE *file = fopen("csv_files/dat100000.csv", "r");
    if (file == NULL)
        printf("Unable to to open dat100000.csv");

    Person *personArray = calloc(100000, sizeof(Person));
    int index = 0;

    while (fscanf(file, "%d,%[^,],%d,%d,%d", &personArray[index].id, personArray[index].name, &personArray[index].age, &personArray[index].weight, &personArray[index].height) != EOF)
        index++;

    gettimeofday(&t1, NULL);
    insertion_sort(personArray, 100000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN TO SORT 100000 ELEMENTS = %f\n", time_taken);
    time[2] = time_taken;
}

void sort_dat1000000()
{
    FILE *file = fopen("csv_files/dat1000000.csv", "r");
    if (file == NULL)
        printf("Unable to to open dat1000000.csv");

    Person *personArray = calloc(1000000, sizeof(Person));
    int index = 0;

    while (fscanf(file, "%d,%[^,],%d,%d,%d", &personArray[index].id, personArray[index].name, &personArray[index].age, &personArray[index].weight, &personArray[index].height) != EOF)
        index++;

    gettimeofday(&t1, NULL);
    insertion_sort(personArray, 1000000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN TO SORT 1000000 ELEMENTS = %f\n", time_taken);
    time[3] = time_taken;
}

void sort_dat7578440()
{
    FILE *file = fopen("csv_files/dat7578440.csv", "r");
    if (file == NULL)
        printf("Unable to to open dat7578440.csv");

    Person *personArray = calloc(7578440, sizeof(Person));
    int index = 0;

    while (fscanf(file, "%d,%[^,],%d,%d,%d", &personArray[index].id, personArray[index].name, &personArray[index].age, &personArray[index].weight, &personArray[index].height) != EOF)
        index++;

    gettimeofday(&t1, NULL);
    insertion_sort(personArray, 7578440);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN TO SORT 7578440 ELEMENTS = %f\n", time_taken);
    time[4] = time_taken;
}

int main()
{
    sort_dat1000();
    sort_dat10000();
    sort_dat100000();
    sort_dat1000000();
    sort_dat7578440();

    return 0;
}