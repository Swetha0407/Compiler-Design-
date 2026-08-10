%{
#include<stdio.h>

int positive_no = 0, negative_no = 0;
%}

%%

-[0-9]+    {
                negative_no++;
                printf("Negative number = %s\n", yytext);
           }

[0-9]+     {
                positive_no++;
                printf("Positive number = %s\n", yytext);
           }

[ \t\n]+   ;

.          ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the numbers:\n");
    yylex();

    printf("\nPositive Count = %d\n", positive_no);
    printf("Negative Count = %d\n", negative_no);

    return 0;
}