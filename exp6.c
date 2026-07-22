#include<stdio.h>
#include<ctype.h>

int main()
{
    char s[50];
    int i=1;

    printf("Enter identifier: ");
    scanf("%s",s);

    if(!(isalpha(s[0])||s[0]=='_'))
    {
        printf("Invalid Identifier");
        return 0;
    }

    while(s[i]!='\0')
    {
        if(!(isalnum(s[i])||s[i]=='_'))
        {
            printf("Invalid Identifier");
            return 0;
        }
        i++;
    }

    printf("Valid Identifier");

    return 0;
}