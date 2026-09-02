%{
#include <stdio.h>
#include <string.h>

char oldword[50] = "cat";
char newword[50] = "dog";
%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, oldword) == 0)
        printf("%s", newword);
    else
        printf("%s", yytext);
}

\n      { printf("\n"); }
.       { printf("%s", yytext); }
%%

int yywrap() { return 1; }

int main()
{
    yyin = fopen("exp39.txt", "r");

    if (!yyin)
    {
        printf("Cannot open file\n");
        return 1;
    }

    yylex();
    fclose(yyin);

    return 0;
}