#include<stdio.h>

int main()
{
    int n;
    int f=1;
    // FILE *input,*output;
    // input =fopen("a.txt","r");
    // 4 modes 
    /*
    Write w (Empty file is created)
    Read r (file is open and pointer is pointing to top of the file)
    Read and write r+
    append a (File open and pointer is pointing to last element)
    */
    // if(input==NULL)
    // {
    //     perror("Error in opening a files\n");
    //     return 1;
    // }
    int i=0,j;
    printf("Enter no.");
    scanf("%d",&n); 
   for(i=1;i<=n;i++)
   {
    f=f*i;
   }
   printf("%d\n",f);
    
}