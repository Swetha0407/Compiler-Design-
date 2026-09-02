%{
#include <stdio.h>
#include <string.h>

char target[50];
int count = 0;
%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, target) == 0)
        count++;
}
[ \t\n]+    { }
.           { }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter word to search: ");
    scanf("%s", target);

    getchar();

    printf("Enter sentence: ");
    yylex();

    printf("Frequency of '%s' = %d\n", target, count);

    return 0;
}