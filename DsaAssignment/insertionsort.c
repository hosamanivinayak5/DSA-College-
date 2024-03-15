#include <stdio.h>

void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // Perform insertion sort
    insertionSort(arr, size);

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
    fprintf(outputFile, "\n\n\n");

    fclose(outputFile);
    

    return 0;
}
