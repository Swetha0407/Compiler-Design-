%{
#include <stdio.h>

int macros = 0;
int headers = 0;
%}

%%

^[ \t]*#[ \t]*define[ \t]+[a-zA-Z_][a-zA-Z0-9_]* {
    macros++;
}

^[ \t]*#[ \t]*include[ \t]*[<"][^>"]+[>"] {
    headers++;
}

.|\n    { }

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
        printf("Cannot open exp20.c\n");
        return 1;
    }

    yylex();

    fclose(yyin);

    printf("Number of Macros = %d\n", macros);
    printf("Number of Header Files = %d\n", headers);

    return 0;
}