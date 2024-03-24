#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;  // Initialize top to -1 indicating an empty stack
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push item, stack is full\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop item, stack is empty\n");
        return -1;  // Return a sentinel value indicating underflow
    } else {
        int item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

// Function to get the top element of the stack without removing it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;  // Return a sentinel value indicating empty stack
    } else {
        return stack->items[stack->top];
    }
}

// Function to display all elements of the stack
void display(Stack *stack, FILE *output) {
    if (isEmpty(stack)) {
        fprintf(output, "Stack is empty\n");
    } else {
        fprintf(output, "Stack:\n");
        for (int i = stack->top; i >= 0; i--) {
            fprintf(output, "%d\n", stack->items[i]);
        }
    }
}

int main() {
    FILE *input, *output;
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    Stack stack;
    initializeStack(&stack);

    int value;
    while (fscanf(input, "%d", &value) == 1) {
        push(&stack, value);
    }

    display(&stack, output);

    fprintf(output, "Popped: %d\n", pop(&stack));
    fprintf(output, "Popped: %d\n", pop(&stack));
    fprintf(output, "Top element: %d\n", peek(&stack));
    display(&stack, output);

    fclose(input);
    fclose(output);

    return 0;
}
