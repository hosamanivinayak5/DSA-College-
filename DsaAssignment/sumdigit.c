#include<stdio.h>

int main()
{ int n,rem,sum=0;
  FILE *input,*output;
  input=fopen("sudig.txt","r+");
  if(input)
  {
    perror("");
  }
   fscanf(input,"%d",&n);
   while(n)
   {rem=n%10;
    sum=sum+rem;
     n=n/10;
   }
   fprintf(input,"\n answer is %d",sum);
   fclose(input);
}