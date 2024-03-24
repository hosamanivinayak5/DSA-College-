#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Enqueue data into the queue
void enqueue(int data) {
    FILE *file = fopen("input_queue.txt", "a"); // Open the input file in append mode
    if (file == NULL) {
        printf("Error opening input file for writing.\n");
        exit(1);
    }

    fprintf(file, "%d\n", data); // Append the data to the file
    fclose(file);
}

// Dequeue data from the queue
int dequeue() {
    int data;
    FILE *inputFile = fopen("input_queue.txt", "r"); // Open the input file in read mode
    if (inputFile == NULL) {
        printf("Error opening input file for reading.\n");
        exit(1);
    }

    // Read the first element from the file
    if (fscanf(inputFile, "%d", &data) != 1) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }

    // Close the input file
    fclose(inputFile);

    // Open the output file in write mode
    FILE *outputFile = fopen("output_queue.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file for writing.\n");
        exit(1);
    }

    // Write remaining elements to the output file
    int temp;
    while (fscanf(inputFile, "%d", &temp) == 1) {
        fprintf(outputFile, "%d\n", temp);
    }

    // Close the output file
    fclose(outputFile);

    // Rename the output file to the input file
    remove("input_queue.txt");
    rename("output_queue.txt", "input_queue.txt");

    return data;
}

// Display the contents of the queue
void display() {
    int data;
    FILE *output, *inputFile = fopen("input_queue.txt", "r"); // Open the input file in read mode
    if (inputFile == NULL) {
        printf("Error opening input file for reading.\n");
        exit(1);
    }
    output=fopen("output.txt","w");
    if(output==NULL)
    {
        printf("Error opening  file\n");
        exit(1);
    }

    printf("Queue Contents:\n");
    while (fscanf(inputFile, "%d", &data) == 1) {
        fprintf(output,"%d\n", data);
    }

    fclose(inputFile);
}

int main() {
    // Enqueue some elements
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Display the contents of the queue
    display();

    // Dequeue and print elements
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    return 0;
}
