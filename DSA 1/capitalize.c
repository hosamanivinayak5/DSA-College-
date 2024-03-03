#include <stdio.h>
#include <ctype.h>
#include<string.h>


void capitalizeFirstLetter(char *word) {
    if (word[0] >= 'a' && word[0] <= 'z') {
        word[0] = toupper(word[0]);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char max[1000];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Read content from file
    while (fscanf(file, "%s", max) != EOF) {
        capitalizeFirstLetter(max);
        fseek(file, -strlen(max), SEEK_CUR);
        fprintf(file, "%s", max);
        fseek(file, 1, SEEK_CUR);
    }

    fclose(file);

    printf("Successfully capitalized the first letter of each word in the file.\n");

    return 0;
}
