#include <stdio.h>

int main() {
    char ch;
    int a, b, c;
    FILE *input;
    FILE *output;

    // Open the input file "simplecal.txt" for reading
    input = fopen("simplecal.txt", "r");
    if (input == NULL) {
        perror("Error in opening input file");
        return 1;
    }

    // Open the output file "results.txt" for writing
    output = fopen("results.txt", "w");
    if (output == NULL) {
        perror("Error in opening output file");
        fclose(input); // Close the input file before exiting
        return 1;
    }

    // Read expressions from the input file and write results to the output file
    while (1) {
        if (fscanf(input, "%d", &a) != 1) {
            printf("Error reading operand a from file\n");
            break;
        }

        if (fscanf(input, "%d", &b) != 1) {
            printf("Error reading operand b from file\n");
            break;
        }

        if (fscanf(input, " %c", &ch) != 1) {
            printf("Error reading operator from file\n");
            break;
        }

        switch (ch) {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                if (b != 0) {
                    c = a / b;
                } else {
                    printf("Error: Division by zero\n");
                    continue;
                }
                break;
            default:
                printf("Error: Invalid operator\n");
                continue;
        }

        // Write the expression and result to the output file
        fprintf(output, "%d %c %d = %d\n", a, ch, b, c);

        // Check for end of file
        if (feof(input)) {
            break;
        }
    }

    // Close both input and output files
    fclose(input);
    fclose(output);

    return 0;
}
