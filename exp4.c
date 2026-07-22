#include<stdio.h>

int main()
{
    char ch;

    printf("Enter an operator: ");
    scanf("%c",&ch);

    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        printf("Valid Arithmetic Operator");
    else
        printf("Invalid Operator");

    return 0;
}