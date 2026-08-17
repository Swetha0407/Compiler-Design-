#include <stdio.h>
#include <string.h>

int main()
{
    char trailing[3][10][10];
    int count[3] = {0, 0, 0};

    /*
       Non-terminals:
       0 -> E
       1 -> T
       2 -> F
    */

    /* TRAILING(F)
       F -> (E) | id
    */
    strcpy(trailing[2][count[2]++], ")");
    strcpy(trailing[2][count[2]++], "id");

    /* TRAILING(T)
       T -> T*F | F
    */
    strcpy(trailing[1][count[1]++], "*");
    strcpy(trailing[1][count[1]++], ")");
    strcpy(trailing[1][count[1]++], "id");

    /* TRAILING(E)
       E -> E+T | T
    */
    strcpy(trailing[0][count[0]++], ")");
    strcpy(trailing[0][count[0]++], "id");

    printf("Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    printf("TRAILING(E) = { ");
    for (int i = 0; i < count[0]; i++)
    {
        printf("%s", trailing[0][i]);

        if (i != count[0] - 1)
            printf(", ");
    }
    printf(" }\n");

    printf("TRAILING(T) = { ");
    for (int i = 0; i < count[1]; i++)
    {
        printf("%s", trailing[1][i]);

        if (i != count[1] - 1)
            printf(", ");
    }
    printf(" }\n");

    printf("TRAILING(F) = { ");
    for (int i = 0; i < count[2]; i++)
    {
        printf("%s", trailing[2][i]);

        if (i != count[2] - 1)
            printf(", ");
    }
    printf(" }\n");

    return 0;
}