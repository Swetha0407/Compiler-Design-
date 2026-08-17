#include <stdio.h>
#include <string.h>
#include <ctype.h>

char exp[100];
int temp = 1;

int main()
{
    int i, j;
    char op1, op2, op;
    char tempvar[10];

    printf("Enter an expression: ");
    scanf("%s", exp);

    /* Handle multiplication and division first */
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '*' || exp[i] == '/')
        {
            op = exp[i];
            op1 = exp[i - 1];
            op2 = exp[i + 1];

            printf("t%d = %c %c %c\n", temp, op1, op, op2);

            /* Replace operation with temporary variable */
            exp[i - 1] = 't';
            exp[i] = temp + '0';
            
            for (j = i + 1; exp[j] != '\0'; j++)
                exp[j] = exp[j + 1];

            temp++;
            i = 0;
        }
    }

    /* Handle addition and subtraction */
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-')
        {
            op = exp[i];
            op1 = exp[i - 1];
            op2 = exp[i + 1];

            printf("t%d = %c %c %c\n", temp, op1, op, op2);

            exp[i - 1] = 't';
            exp[i] = temp + '0';

            for (j = i + 1; exp[j] != '\0'; j++)
                exp[j] = exp[j + 1];

            temp++;
            i = 0;
        }
    }

    return 0;
}