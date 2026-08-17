#include <stdio.h>
#include <string.h>

int main()
{
    char leading[3][10][10];
    int count[3] = {0, 0, 0};

    /*
       Non-terminals:
       0 -> E
       1 -> T
       2 -> F
    */

    /* LEADING(F) */
    strcpy(leading[2][count[2]++], "(");
    strcpy(leading[2][count[2]++], "id");

    /* LEADING(T)
       T -> T * F
       T -> F
    */
    strcpy(leading[1][count[1]++], "*");
    strcpy(leading[1][count[1]++], "(");
    strcpy(leading[1][count[1]++], "id");

    /* LEADING(E)
       E -> E + T
       E -> T
    */
    strcpy(leading[0][count[0]++], "+");
    strcpy(leading[0][count[0]++], "(");
    strcpy(leading[0][count[0]++], "id");

    printf("Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    printf("LEADING(E) = { ");
    for (int i = 0; i < count[0]; i++)
    {
        printf("%s", leading[0][i]);

        if (i != count[0] - 1)
            printf(", ");
    }
    printf(" }\n");

    printf("LEADING(T) = { ");
    for (int i = 0; i < count[1]; i++)
    {
        printf("%s", leading[1][i]);

        if (i != count[1] - 1)
            printf(", ");
    }
    printf(" }\n");

    printf("LEADING(F) = { ");
    for (int i = 0; i < count[2]; i++)
    {
        printf("%s", leading[2][i]);

        if (i != count[2] - 1)
            printf(", ");
    }
    printf(" }\n");

    return 0;
}