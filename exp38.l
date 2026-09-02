%{
#include <stdio.h>
#include <string.h>

char longest[100] = "";
%}

%%
[a-zA-Z]+ {
    if (strlen(yytext) > strlen(longest))
        strcpy(longest, yytext);
}

[ \t\n]+    { }
.           { }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter a sentence: ");
    yylex();

    printf("Longest word = %s\n", longest);
    printf("Length = %lu\n", strlen(longest));

    return 0;
}