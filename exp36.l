%{
#include <stdio.h>
int a, b;
%}

%%
[0-9]+ {
    if (a == 0)
        a = atoi(yytext);
    else
        b = atoi(yytext);
}

[ \t]+    { }

[+]       { printf("Addition = %d\n", a + b); }
[-]       { printf("Subtraction = %d\n", a - b); }
[*]       { printf("Multiplication = %d\n", a * b); }
[/]       { 
            if (b != 0)
                printf("Division = %d\n", a / b);
          }

\n        { }
.         { }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter expression: ");
    yylex();
    return 0;
}