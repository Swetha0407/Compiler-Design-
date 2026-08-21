%{
#include <stdio.h>
%}

%%

[0-9]+(\.[0-9]+)?      { printf("Constant: %s\n", yytext); }
\"([^\"\\]|\\.)*\"      { printf("String Constant: %s\n", yytext); }
'([^'\\]|\\.)'          { printf("Character Constant: %s\n", yytext); }

.                       { }

%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("exp20a.c", "r");

    if (yyin == NULL)
    {
        printf("Cannot open exp20a.c\n");
        return 1;
    }

    yylex();

    fclose(yyin);

    return 0;
}