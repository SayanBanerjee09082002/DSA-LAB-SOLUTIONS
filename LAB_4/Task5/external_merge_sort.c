#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1000000 // 1M entries per chunk

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void mergeFiles(FILE *file1, FILE *file2, FILE *outfile) {
    int num1, num2;
    int res1, res2;

    // Read the first number from each file
    res1 = fscanf(file1, "%d", &num1);
    res2 = fscanf(file2, "%d", &num2);

    // Merge until we reach the end of either file
    while (res1 > 0 && res2 > 0) {
        if (num1 <= num2) {
            fprintf(outfile, "%d\n", num1);
            res1 = fscanf(file1, "%d", &num1);
        } else {
            fprintf(outfile, "%d\n", num2);
            res2 = fscanf(file2, "%d", &num2);
        }
    }

    // If there are any remaining numbers in file1, write them to the output file
    while (res1 > 0) {
        fprintf(outfile, "%d\n", num1);
        res1 = fscanf(file1, "%d", &num1);
    }

    // If there are any remaining numbers in file2, write them to the output file
    while (res2 > 0) {
        fprintf(outfile, "%d\n", num2);
        res2 = fscanf(file2, "%d", &num2);
    }
}

int main() {
    FILE *inputFile = fopen("dat7578440.csv", "r");
    FILE *tempFiles[100]; // Array to hold temporary files
    char tempFileName[20];
    int *chunk;
    int i, j, numChunks, numElements, tempFileCount = 0;

    // Allocate memory for a chunk
    chunk = (int*)malloc(CHUNK_SIZE * sizeof(int));

    // Read the input file in chunks, sort them, and write them to temporary files
    while (!feof(inputFile)) {
        numElements = 0;
        // Read CHUNK_SIZE elements into the chunk array
        while (numElements < CHUNK_SIZE && fscanf(inputFile, "%d", &chunk[numElements]) == 1) {
            numElements++;
        }

        // Sort the chunk
        qsort(chunk, numElements, sizeof(int), compare);

        // Create a temporary file to write the sorted chunk
        sprintf(tempFileName, "temp%d.txt", tempFileCount);
        tempFiles[tempFileCount] = fopen(tempFileName, "w");
        tempFileCount++;

        // Write the sorted chunk to the temporary file
        for (i = 0; i < numElements; i++) {
            fprintf(tempFiles[tempFileCount - 1], "%d\n", chunk[i]);
        }
    }

    fclose(inputFile);

    // Merge the temporary files
    numChunks = tempFileCount;
    while (numChunks > 1) {
        for (i = 0, j = 0; i < numChunks; i += 2, j++) {
            // Open two files for merging
            FILE *file1 = tempFiles[i];
            FILE *file2 = (i + 1 < numChunks) ? tempFiles[i + 1] : NULL;

            // Create a new temporary file for the merged chunk
            sprintf(tempFileName, "temp%d.txt", tempFileCount);
            FILE *outfile = fopen(tempFileName, "w");
            tempFileCount++;

            // Merge the two chunks
            mergeFiles(file1, file2, outfile);

            // Close the files
            fclose(file1);
            if (file2 != NULL) fclose(file2);
            fclose(outfile);

            // Remove the merged files
            remove(tempFiles[i]);
            if (file2 != NULL) remove(tempFiles[i + 1]);

            // Update the temporary file array
            tempFiles[j] = fopen(tempFileName, "r");
        }
        numChunks = j;
    }

    // Rename the final temporary file to the output file name
    rename(tempFileName, "sorted_dat7578440.csv");

    // Clean up: close and remove temporary files
    for (i = 0; i < numChunks; i++) {
        fclose(tempFiles[i]);
        remove(tempFiles[i]);
    }

    free(chunk);
    printf("External merge sort completed successfully.\n");

    return 0;
}
