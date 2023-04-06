#include<stdio.h>
#include<conio.h>

int func(int a)
{
    int b = 5;
    a = a - b;

    return a;
}

int main ()
{
    int a = 10;
    int c = func(10);
    printf("%d",c);
}


int funcf(int a)
{
    int b = 5;
    a = a - b;

    return a;
}