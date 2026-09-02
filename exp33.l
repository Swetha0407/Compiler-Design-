%{
#include <stdio.h>
%}

%%
"https://"[a-zA-Z0-9.-]+"."[a-zA-Z][a-zA-Z]* {
    printf("Valid URL\n");
}

"http://"[a-zA-Z0-9.-]+"."[a-zA-Z][a-zA-Z]* {
    printf("Valid URL\n");
}

.* {
    printf("Invalid URL\n");
}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter URL: ");
    yylex();
    return 0;
}