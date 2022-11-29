#include<stdio.h>
#include<conio.h>

void main()
{

int one=0,two=0;
printf("Enter students percentage to check what their grade is:");
scanf("%d",&one);

if(one >= 95 && one <= 100)
{
    printf("The grade is A+");
}
else if(one >= 90 && one <= 94)
{
    printf("The grade is A");
}
else if(one >= 85 && one <= 89)
{
    printf("The grade is A-");
}
else if(one >= 80 && one <= 84)
{
    printf("The grade is B+");
}
else if(one >= 75 && one <= 79)
{
    printf("The grade is B");
}
else if(one >= 70 && one <= 74)
{
    printf("The grade is B-");
}
else if(one >= 65 && one <= 69)
{
    printf("The grade is C+");
}
else if(one >= 60 && one <= 64)
{
    printf("The grade is C");
}
else if(one > 100)
{
    printf("Enter result in percentile");
}
else
{
    printf("You have failed!!!");
}
}