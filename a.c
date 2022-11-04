#include<stdio.h>

void main() 
{
    int table;
    printf("enter any number you want find its table");
    scanf("%d",&table);

    for(int i=1;i<=10;i++)
    {
        int t = i*table;
        printf("%d\n",t);
    }
}

