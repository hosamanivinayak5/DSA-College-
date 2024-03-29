#include <stdio.h>

int main() {
    int n;
    int f = 1;
    
    FILE *input, *output;
    
    // Open input file
    input = fopen("a.txt", "r");
    if (input == NULL) {
        perror("Error in opening input file");
        return 1;
    }
    
    // Read the number from the input file
    if (fscanf(input, "%d", &n) != 1) {
        printf("Error reading from input file");
        fclose(input);
        return 1;
    }
    
    // Calculate factorial
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    
    // Close input file
    fclose(input);
    
    // Open output file
    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error in opening output file");
        return 1;
    }
    
    // Write the factorial to the output file
    fprintf(output, "%d\n", f);
    
    // Close output file
    fclose(output);
    
    return 0;
}


  // FILE *input,*output;
    // input =fopen("a.txt","r");
    // 4 modes 
    /*
    Write w (Empty file is created)
    Read r (file is open and pointer is pointing to top of the file)
    Read and write r+
    append a (File open and pointer is pointing to last element)
    */
    // if(input==NULL)
    // {
    //     perror("Error in opening a files\n");
    //     return 1;
    // }