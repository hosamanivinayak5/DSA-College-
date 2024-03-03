#include<stdio.h>

int main()
{
    char ch;
int a,b,c;
while (1)
{    printf("Enter operand a:");
scanf("%d",&a);
printf("Enter operand b:");
scanf("%d",&b);
    printf("Enter operator:");
scanf("%*c",&ch);

    switch (ch)
    {
    case '+':
        c=a+b;
        break;
    case '-':  c=a-b;
    break;
    case'*' :  c=a*b;
    break;
case  '/':  c=a/b;
break;

    default:
        break;
    }
    printf("answer %d\n",c);
}


}