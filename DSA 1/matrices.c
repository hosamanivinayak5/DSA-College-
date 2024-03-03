#include<stdio.h>

int main()
{
    int a[2][2],b[2][2],c[2][2],i,j;
    printf("Enter first matrix:");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
        scanf("%d",&a[i][j]);
        }
        
    }  
    printf("Enter second matrix:");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
        scanf("%d",&b[i][j]);
        }
      
    } 
     printf("Your first matrix is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
        printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Your second matrix is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
        printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("Sum of the 2 matrices is :\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    printf("Difference of the 2 matrices is :\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }


}