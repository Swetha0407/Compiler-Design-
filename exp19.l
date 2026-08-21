%{
#include <stdio.h>

int characters = 0;
int words = 0;
int lines = 1;

%}

%%

"//".*                  { }
"/*"([^*]|\*+[^*/])*\*+"/"  { 
                            int i;
                            for(i = 0; i < yyleng; i++)
                                if(yytext[i] == '\n')
                                    lines++;
                          }

[ \t]+                  { }

\n                      { lines++; }

[a-zA-Z_][a-zA-Z0-9_]{0,30} {
                            words++;
                            characters += yyleng;
                          }

[0-9]+                  {
                            words++;
                            characters += yyleng;
                          }

\"([^\"\\]|\\.)*\"      {
                            words++;
                            characters += yyleng;
                          }

[^\t \n]                {
                            words++;
                            characters++;
                          }

%%

int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <input.c>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if(yyin == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    yylex();

    fclose(yyin);

    printf("\nNumber of Characters = %d", characters);
    printf("\nNumber of Lines      = %d", lines);
    printf("\nNumber of Words      = %d\n", words);

    return 0;
}