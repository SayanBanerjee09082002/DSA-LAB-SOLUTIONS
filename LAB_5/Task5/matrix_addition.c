#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#define ROWS 600
#define COLUMNS 800

struct timeval t1, t2;
double time_taken;

void matrix_addition_by_rows(int** matrix1, int** matrix2, int** result_matrix) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
}

void matrix_addition_by_columns(int** matrix1, int** matrix2, int** result_matrix) {
    for (int  j= 0; j < COLUMNS; j++)
        for (int i = 0; i < ROWS; i++)
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
}

int main() {
    //Allocating memory to matrices
    int **matrix1 = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        matrix1[i] = (int *)malloc(COLUMNS * sizeof(int));
    }

    int **matrix2 = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        matrix2[i] = (int *)malloc(COLUMNS * sizeof(int));
    }

    int **resultant = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        resultant[i] = (int *)malloc(COLUMNS * sizeof(int));
    }

    //Populating the matrices
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++) {
            matrix1[i][j] = rand();
            matrix2[i][j] = rand();
        }
            
    gettimeofday(&t1, NULL);
    matrix_addition_by_rows(matrix1, matrix2, resultant);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR ADDITION BY ROWS    = %f seconds\n", time_taken);

    gettimeofday(&t1, NULL);
    matrix_addition_by_columns(matrix1, matrix2, resultant);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME TAKEN FOR ADDITION BY COLUMNS = %f seconds\n", time_taken);
}