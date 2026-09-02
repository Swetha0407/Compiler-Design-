%{
#include <stdio.h>
%}

%%
"#include".*                { printf("PREPROCESSOR: %s\n", yytext); }
"int"|"char"|"float"|"void" { printf("KEYWORD: %s\n", yytext); }
"printf"|"scanf"            { printf("FUNCTION: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*      { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+                      { printf("CONSTANT: %s\n", yytext); }
\"([^\"\\]|\\.)*\"          { printf("STRING: %s\n", yytext); }
[+\-*/=]                    { printf("OPERATOR: %s\n", yytext); }
[(){};,]                    { printf("SPECIAL SYMBOL: %s\n", yytext); }
[ \t\n]+                    { }
.                           { printf("SYMBOL: %s\n", yytext); }
%%

int yywrap() { return 1; }

int main()
{
    yyin = fopen("exp29.c", "r");
    if (!yyin)
    {
        printf("Cannot open file\n");
        return 1;
    }

    yylex();
    fclose(yyin);
    return 0;
}