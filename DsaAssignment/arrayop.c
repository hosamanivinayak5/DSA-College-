#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int array[100], size, i;
    int sum = 0, largest, smallest;

    // Open input file
    inputFile = fopen("arayop.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read array size and elements from file
    if (fscanf(inputFile, "%d", &size) != 1) {
        printf("Error reading array size from file!\n");
        fclose(inputFile);
        return 1;
    }
    for (i = 0; i < size; ++i) {
        if (fscanf(inputFile, "%d", &array[i]) != 1) {
            printf("Error reading element %d from file!\n", i);
            fclose(inputFile);
            return 1;
        }
    }
    fclose(inputFile);

    // Find sum, largest, and smallest element
    sum = array[0];
    largest = array[0];
    smallest = array[0];
    for (i = 1; i < size; ++i) {
        sum += array[i];
        if (array[i] > largest) {
            largest = array[i];
        }
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    // Calculate average
   double average = (double)sum / size;

    // Open output file
    outputFile = fopen("arayopout.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write results to file
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2lf\n", average);
    fprintf(outputFile, "Largest element: %d\n", largest);
    fprintf(outputFile, "Smallest element: %d\n", smallest);

    fclose(outputFile);
    printf("Results have been written to 'output.txt'\n");

    return 0;
}
