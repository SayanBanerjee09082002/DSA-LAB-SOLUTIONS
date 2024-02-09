#include "merge_sort.h"
#include <stdlib.h>

void mergeAux(Person *L1, int s1, int e1, Person *L2, int s2, int e2, Person *L3, int s3, int e3)
{
    int i = s1, j = s2, k = s3;

    while (i <= e1 && j <= e2)
    {
        if (L1[i].height < L2[j].height)
            L3[k++] = L1[i++];
        else
            L3[k++] = L2[j++];
    }

    while (i <= e1)
        L3[k++] = L1[i++];

    while (j <= e2)
        L3[k++] = L2[j++];
}

void merge(Person *array, int start, int middle, int end)
{
    Person *tempArray = malloc((end - start + 1) * sizeof(Person));

    mergeAux(array, start, middle, array, middle + 1, end, tempArray, 0, end - start);

    for (int i = 0; i < end - start + 1; i++)
        array[start + i] = tempArray[i];

    free(tempArray);
}

void merge_sort(Person *array, int start, int end)
{
    if (end - start < 1)
        return;

    int middle = (start + end) / 2;

    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, end);
    merge(array, start, middle, end);
}
