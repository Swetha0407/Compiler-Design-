%{
#include<stdio.h>
%}

%%

[a-z0-9._]+@[a-z]+(\.com|\.in)   { printf("It is valid\n"); }
.+                               { printf("It is not valid\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the mail: ");
    yylex();
    return 0;
}
