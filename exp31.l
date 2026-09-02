%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"for"|"while"|"return" {
    printf("Keyword: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Identifier: %s\n", yytext);
}

[ \t\n]+    { }
.           { }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter C statement: ");
    yylex();
    return 0;
}