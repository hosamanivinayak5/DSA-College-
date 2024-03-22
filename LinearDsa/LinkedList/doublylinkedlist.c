#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

void addAtBeg(struct node **head, int);
void addAtEnd(struct node **head, int);
int deleteAtBeg(struct node **head);
int deleteAtEnd(struct node **head);
void display(struct node* head, FILE *file);

int main()
{
    struct node* head = NULL;
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
            addAtBeg(&head, e);
            break;

        case 2:
            fscanf(inputFile, "%d", &e);
            addAtEnd(&head, e);
            break;

        case 3:
            if (head == NULL)
            {
                fprintf(outputFile, "List is empty.\n");
                break;
            }
            e = deleteAtBeg(&head);
            fprintf(outputFile, "Deleted element: %d\n", e);
            break;

        case 4:
            if (head == NULL)
            {
                fprintf(outputFile, "List is empty.\n");
                break;
            }
            e = deleteAtEnd(&head);
            fprintf(outputFile, "Deleted element: %d\n", e);
            break;

        case 5:
            if (head == NULL)
            {
                fprintf(outputFile, "List is empty.\n");
                break;
            }
            display(head, outputFile);
            break;
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

void addAtBeg(struct node **head, int e)
{
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    struct node* p = (*head)->prev;
    newNode->data = e;
    newNode->next = newNode;
    newNode->prev = newNode;

    if ((*head) == NULL)
    {
        (*head) = newNode;
        return 0;
    }
    newNode->next = (*head);
    newNode->prev = (*head)->prev;
    (*head)->prev = newNode;
    p = newNode->prev;
    (*head) = newNode;
}

void addAtEnd(struct node **head, int e)
{
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = e;
    newNode->next = newNode;
    newNode->prev = newNode;

    if ((*head) == NULL)
    {
        (*head) = newNode;
        return 0;
    }
    struct node* cur = (*head)->prev;
    newNode->next = (*head);
    newNode->prev = cur;
    cur->next = newNode;
    (*head)->prev = newNode;
}

int deleteAtBeg(struct node **head)
{
    int e;
    if ((*head)->next == (*head))
    {
        e = (*head)->data;
        free((*head));
        (*head) = NULL;
        return e;
    }
    struct node* cur = (*head)->next;
    struct node* p = (*head)->prev;
    cur->prev = p;
    p->next = cur;
    e = (*head)->data;
    free((*head));
    (*head) = cur;
    return e;
}

int deleteAtEnd(struct node **head)
{
    int e;
    if ((*head)->next == (*head))
    {
        e = (*head)->data;
        free((*head));
        (*head) = NULL;
        return e;
    }
    struct node* cur = (*head)->prev;
    struct node* p = cur->prev;
    p->next = (*head);
    e = cur->data;
    free(cur);
    return e;
}

void display(struct node* head, FILE *file)
{
    struct node* cur = head;
    do
    {
        fprintf(file, "%d\n", cur->data);
        cur = cur->next;
    }
    while (cur != head);
}
