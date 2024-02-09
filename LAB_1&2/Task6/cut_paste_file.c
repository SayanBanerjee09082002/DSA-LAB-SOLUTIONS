#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file1, *file2;

    // Opening the fileS
    file1 = fopen("text1.txt", "rb+");
    file2 = fopen("text2.txt", "w");

    if (file1 == NULL || file2 == NULL)
    {
        printf("Error opening file!");
        return 0;
    }

    //Performing cut paste operation
    char copy = fgetc(file1);
    while (copy != EOF) {
        fputc(' ',file1);
        fputc(copy,file2);
        copy = fgetc(file1);
    }

    return 0;
}