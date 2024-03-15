#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int arr[100], size, i;

    // Open input file
    inputFile = fopen("arayop.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read the size of the array from file
    if (fscanf(inputFile, "%d", &size) != 1) {
        printf("Error reading size of the array from file!\n");
        fclose(inputFile);
        return 1;
    }

    // Read the elements of the array from file
    for (i = 0; i < size; ++i) {
        if (fscanf(inputFile, "%d", &arr[i]) != 1) {
            printf("Error reading element %d from file!\n", i);
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);

    // Perform bubble sort
    bubbleSort(arr, size);

    // Open output file
    outputFile = fopen("arayopout.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write the sorted array to file
    fprintf(outputFile, "Sorted array:\n");
    for (i = 0; i < size; ++i) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);
   

    return 0;
}
