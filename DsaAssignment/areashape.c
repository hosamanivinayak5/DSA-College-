#include <stdio.h>
#include <math.h>
#include<string.h>
#define PI 3.14159265358979323846

double rectangleArea(double length, double width) {
    return length * width;
}

double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

double circleArea(double radius) {
    return PI * radius * radius;
}

int main() {
    FILE *inputFile, *outputFile;
    char shape[20];
    double parameter1, parameter2;

    // Open input file
    inputFile = fopen("ashape.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read shape and parameters from file
    if (fscanf(inputFile, "%s", shape) != 1 ||
        fscanf(inputFile, "%lf", &parameter1) != 1 ||
        fscanf(inputFile, "%lf", &parameter2) != 1) {
        printf("Error reading input from file!\n");
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);

    double area;
    if (strcmp(shape, "rectangle") == 0) {
        area = rectangleArea(parameter1, parameter2);
    } else if (strcmp(shape, "triangle") == 0) {
        area = triangleArea(parameter1, parameter2);
    } else if (strcmp(shape, "circle") == 0) {
        area = circleArea(parameter1);
    } else {
        printf("Invalid shape!\n");
        return 1;
    }

    // Open output file
    outputFile = fopen("ashape.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write result to file
    fprintf(outputFile, "Area of %s: %.2f\n", shape, area);

    fclose(outputFile);
    printf("Area of %s has been written to 'output.txt'\n", shape);

    return 0;
}
