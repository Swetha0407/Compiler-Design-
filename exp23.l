%{
#include <stdio.h>

int line = 1;
%}

%%

\n              {
                    line++;
                    printf("\n%d ", line);
                }

.               {
                    printf("%s", yytext);
                }

%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("exp23.c", "r");

    if (yyin == NULL)
    {
        printf("Cannot open exp23.c\n");
        return 1;
    }

    printf("%d ", line);

    yylex();

    fclose(yyin);

    return 0;
}