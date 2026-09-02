%{
#include <stdio.h>
int count = 0;
%}

%%
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] {
    count++;
}
\n      { }
.       { }
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter a sentence: ");
    yylex();
    printf("Number of consonants = %d\n", count);
    return 0;
}