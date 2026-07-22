#include<stdio.h>
#include<string.h>

int main()
{
    char s[200];

    fgets(s,sizeof(s),stdin);

    if(strncmp(s,"//",2)==0)
        printf("Single line comment");
    else if(strncmp(s,"/*",2)==0 && strstr(s,"*/"))
        printf("Multi line comment");
    else
        printf("Not a comment");

    return 0;
}