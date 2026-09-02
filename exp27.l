%{
#include <stdio.h>
%}

%%
abc     { printf("ABC"); }
\n      { printf("\n"); }
.       { printf("%s", yytext); }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}