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
        printf("Pushed %d to the stack\n", value);
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
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->items[i]);
        }
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    display(&stack);

    return 0;
}
