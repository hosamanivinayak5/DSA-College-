#include<stdio.h>
#include<math.h>
#include<string.h>

int isprime(int n) {
    int i;
    int a=sqrt(n);
    if (n <= 1)
        return 0;  // 0 and 1 are not prime
    for (i = 2; i <= a; i++) {
        if (n % i == 0)
            return 0; // Not prime
    }
    return 1; // Prime
}

int main() {
    int n;
    FILE *input, *output;
    char a[100]; // Array to store the result

    input = fopen("a.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }
    fscanf(input, "%d", &n);
    fclose(input);

    if (isprime(n))
        strcpy(a, "Is prime");
    else
        strcpy(a, "Is not prime");

    output = fopen("output.txt", "w"); // Open a new file for writing
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }
    fprintf(output, "%s", a);
    fclose(output);

    return 0;
}
