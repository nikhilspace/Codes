#include<stdio.h>

void main () 
{
    int table;
    printf("enter the number of which table you want");
    scanf("%d",&table);

    for (int i=1;i != 11;i++)
    {   
        int result = i*table;
        printf("%d\n",result);
    }
}