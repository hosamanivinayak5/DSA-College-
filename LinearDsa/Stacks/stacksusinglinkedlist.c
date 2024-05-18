#include<stdio.h>
struct node {
    int opno;
    struct node *next;
};
typedef struct node * Stack;
void initstack(Stack *s){
    *s=NULL;
    
}
int main()
{  Stack s;
   initstack(&s);
   redo(&s);
    
}