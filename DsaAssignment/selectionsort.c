#include <stdio.h>

void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size - 1; ++i) {
        minIndex = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element of unsorted subarray
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    // Perform selection sort
    selectionSort(arr, size);

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
    printf("Sorted array has been written to 'output.txt'\n");

    return 0;
}
