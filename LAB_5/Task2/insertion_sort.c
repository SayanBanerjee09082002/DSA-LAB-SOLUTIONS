#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

struct timeval t1, t2;
double time_taken;

// recursive insertion sort
void insertionSortR(int *arr, int n)
{
    if (n <= 1)
        return;
    insertionSortR(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// iterative insertion sort
void insertionSortI(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int last = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > last)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }
}

int main()
{
    FILE *fp = fopen("numbers1000.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int recursive_sort[1000], iterative_sort[1000];
    int i = 0;

    while (fscanf(fp, "%d", &recursive_sort[i]) != EOF && i < 1000)
        i++;

    fclose(fp);

    for (int i = 0; i < 1000; i++)
        iterative_sort[i] = recursive_sort[i];

    gettimeofday(&t1, NULL);
    insertionSortR(recursive_sort, 1000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR RECURSIVE INSERTION SORT = %f seconds\n", time_taken);

    gettimeofday(&t1, NULL);
    insertionSortI(iterative_sort, 1000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR ITERATIVE INSERTION SORT = %f seconds\n", time_taken);

    return 0;
}