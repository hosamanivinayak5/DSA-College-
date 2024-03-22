#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addatbeg(struct node **, int);
void displayList(struct node *head, FILE *file);
void alternate(struct node *);

int main()
{
    struct node *head = NULL;
    int e, ch;

    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Error opening files.\n");
        exit(1);
    }

    while (1)
    {
        if (fscanf(inputFile, "%d", &ch) != 1)
            break;

        switch (ch)
        {
        case 1:
            fscanf(inputFile, "%d", &e);
            addatbeg(&head, e);
            break;

        case 2:
            fprintf(outputFile, "The roll.no after removing alternate: ");
            alternate(head);
            displayList(head,outputFile);
            break;

        case 3:
            fclose(inputFile);
            fclose(outputFile);
            exit(0);
            break;
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

void addatbeg(struct node **head, int e)
{
    struct node *p;

    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        perror(" ");
        return;
    }

    p->data = e;
    p->next = *head;
    *head = p;
}

void displayList(struct node *head, FILE *file)
{
    struct node *cur = head;
    if (head == NULL)
    {
        fprintf(file, "List is empty.\n");
        return;
    }
    while (cur != NULL)
    {
        fprintf(file, "%d   ", cur->data);
        cur = cur->next;
    }
    fprintf(file, "\n");
}

void alternate(struct node *head)
{
    struct node *cur = head;
    struct node *prev = NULL;

    while (cur && cur->next)
    {
        prev = cur;
        cur = cur->next;
        prev->next = cur->next;
        free(cur);
        cur = prev->next;
    }
}
