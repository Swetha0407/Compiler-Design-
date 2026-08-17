#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int E();
int T();

int E()
{
    if (!T())
        return 0;

    if (input[pos] == '+')
    {
        pos++;
        return E();
    }

    return 1;
}

int T()
{
    if (input[pos] == 'i' && input[pos + 1] == 'd')
    {
        pos += 2;
        return 1;
    }

    return 0;
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    if (E() && input[pos] == '\0')
        printf("String is ACCEPTED by the grammar.\n");
    else
        printf("String is REJECTED by the grammar.\n");

    return 0;
}