#include<stdio.h>
#include<stdlib.h>
struct  node 
{
    /* data */
    int data;
    struct node *next;
};
typedef struct node *Node;
void displaylist(Node head);
Node getNode()
{
    Node  new ;

    new=(Node)malloc(sizeof(struct node ));
     if(new==NULL)
  {
    perror("Error");
    exit(0);
  }
  new->next=NULL;
return new;

}
Node createNode()
{
    Node temp;
    temp=getNode();
    scanf("%d",&temp->data);
    return temp;
}
Node insertNodeAtEnd(Node head)
{
    Node temp,cur;
     temp=createNode();
     temp->next=NULL;
     if(head==NULL)
{
    return temp;
}
   cur=head;
   while(cur->next!=NULL)
    {
        cur=cur->next;
        
    }
    cur->next=temp;
    return head;
}
void displaylist(Node head)
{
    Node cur;
    if(head==NULL)
    {
        printf("List empty\n");
        return;

    }
    printf("The elements are :");
    cur=head;
    while (cur!=NULL)
    {
      printf("%d ",cur->data);
      cur=cur->next;
    }
    printf("\n");

    
}
int main()
{  
    Node temp;
    Node head=NULL;
   head= insertNodeAtEnd(head);
   head= insertNodeAtEnd(head);
  displaylist(head);
}