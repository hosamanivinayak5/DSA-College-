#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *inputFileA, *inputFileB, *outputFile;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Open input file for matrix A
    inputFileA = fopen("matrixA.txt", "r");
    if (inputFileA == NULL) {
        printf("Error opening input file for matrix A!\n");
        return 1;
    }

    // Read dimensions of matrix A from file
    if (fscanf(inputFileA, "%d %d", &rowsA, &colsA) != 2) {
        printf("Error reading dimensions of matrix A from file!\n");
        fclose(inputFileA);
        return 1;
    }

    // Read elements of matrix A from file
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            if (fscanf(inputFileA, "%d", &matrixA[i][j]) != 1) {
                printf("Error reading elements of matrix A from file!\n");
                fclose(inputFileA);
                return 1;
            }
        }
    }

    fclose(inputFileA);

    // Open input file for matrix B
    inputFileB = fopen("matrixB.txt", "r");
    if (inputFileB == NULL) {
        printf("Error opening input file for matrix B!\n");
        return 1;
    }

    // Read dimensions of matrix B from file
    if (fscanf(inputFileB, "%d %d", &rowsB, &colsB) != 2) {
        printf("Error reading dimensions of matrix B from file!\n");
        fclose(inputFileB);
        return 1;
    }

    // Read elements of matrix B from file
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            if (fscanf(inputFileB, "%d", &matrixB[i][j]) != 1) {
                printf("Error reading elements of matrix B from file!\n");
                fclose(inputFileB);
                return 1;
            }
        }
    }

    fclose(inputFileB);

    // Check if dimensions match for addition
    if (rowsA != rowsB || colsA != colsB) {
        printf("Error: Matrices have different dimensions!\n");
        return 1;
    }

    // Perform matrix addition
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Open output file
    outputFile = fopen("matrixop.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file for addition result!\n");
        return 1;
    }

    // Write the result to output file
    fprintf(outputFile, "Matrix Addition Result:\n");
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            fprintf(outputFile, "%d ", result[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    printf("Matrix addition result has been written to 'matrixop.txt'\n");

    return 0;
}
