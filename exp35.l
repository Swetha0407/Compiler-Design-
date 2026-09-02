%{
#include <stdio.h>
%}

%%
^[0-9]$     { printf("It is a Digit\n"); }
.*          { printf("It is not a Digit\n"); }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter a character: ");
    yylex();
    return 0;
}