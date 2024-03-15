#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char str1[100], str2[100], result[200];
    char operation[4]; // Considering "cmp" operation as string

    // Open input file
    inputFile = fopen("strinp.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read strings and operation from file
    if (fscanf(inputFile, "%s %s %s", str1, str2, operation) != 3) {
        printf("Error reading input from file!\n");
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);

    // Perform operation
    if (strcmp(operation, "c") == 0) { // Concatenation
        strcpy(result, str1);
        strcat(result, str2);
    } else if (strcmp(operation, "C") == 0) { // Copy
        strcpy(result, str2);
    } else if (strcmp(operation, "cmp") == 0) { // Comparison
        if (strcmp(str1, str2) == 0) {
            strcpy(result, "Strings are equal");
        } else {
            strcpy(result, "Strings are not equal");
        }
    } else {
        printf("Invalid operation!\n");
        return 1;
    }

    // Open output file
    outputFile = fopen("strioup.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write result to file
    fprintf(outputFile, "%s\n", result);

    fclose(outputFile);
    printf("Result has been written to 'output.txt'\n");

    return 0;
}
