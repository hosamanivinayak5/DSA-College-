#include<stdio.h>
int main()
{   FILE *input,*output;
    output=fopen("a2.txt","w");
    if(output==NULL)
    {
        perror("");
    }
    fprintf(output,"Hello world\n");
    fclose(output);
}