#include "insertion_sort.h"

void insertion_sort(Person *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        Person key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j].height > key.height)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}
