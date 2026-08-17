#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;

    printf("Enter the text (press Ctrl+D to stop):\n");

    while ((ch = getchar()) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    printf("\nNumber of Characters = %d\n", characters);
    printf("Number of Words      = %d\n", words);
    printf("Number of Lines      = %d\n", lines);

    return 0;
}