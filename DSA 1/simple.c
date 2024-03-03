#include<stdio.h>

int main() {
    char ch;
    int a, b, c;

    while (1) {
        printf("Enter operand a: ");
        scanf("%d", &a);

        printf("Enter operand b: ");
        scanf("%d", &b);

        printf("Enter operator: ");
        scanf(" %c", &ch); // Added space before %c to consume any leading whitespace

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

        printf("Answer: %d\n", c);
        
     
        printf("Do you want to continue (Y/N)? ");
        scanf(" %c", &ch); 
        if (ch == 'N' || ch == 'n') {
            break;
        }
    }

    return 0;
}
