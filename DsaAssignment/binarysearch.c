#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Return index of found element
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if element not found
}

int main() {
    FILE *inputFile, *outputFile;
    int arr[100], size, key, result;

    // Open input file
    inputFile = fopen("arayop.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read array size, array elements, and key from file
    if (fscanf(inputFile, "%d", &size) != 1) {
        printf("Error reading array size from file!\n");
        fclose(inputFile);
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        if (fscanf(inputFile, "%d", &arr[i]) != 1) {
            printf("Error reading element %d from file!\n", i);
            fclose(inputFile);
            return 1;
        }
    }
    if (fscanf(inputFile, "%d", &key) != 1) {
        printf("Error reading key from file!\n");
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);

    // Perform binary search
    result = binarySearch(arr, size, key);

    // Open output file
    outputFile = fopen("arayopout.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write result to file
    if (result != -1) {
        fprintf(outputFile, "Element %d found at index %d\n", key, result);
    } else {
        fprintf(outputFile, "Element %d not found in the array\n", key);
    }

    fclose(outputFile);
    

    return 0;
}
