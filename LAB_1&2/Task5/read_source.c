#include <stdio.h>
#include <stdlib.h>

int main()
{
    // file pointer
    FILE *fp = NULL;
    int ch = 0;

    // open the file
    fp = fopen(__FILE__, "r");
    if (fp == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }

    // read till EOF
    do
    {
        ch = fgetc(fp);
        printf("%c", ch);
    } while (ch != EOF);
    
    // close open file
    fclose(fp);
    return 0;
}