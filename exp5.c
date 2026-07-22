#include<stdio.h>

int main()
{
    FILE *fp=fopen("inputexp5.txt","r");
    char ch;
    int space=0,newline=0;

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch==' ')
            space++;
        else if(ch=='\n')
            newline++;
    }

    printf("White spaces : %d\n",space);
    printf("New lines : %d\n",newline);

    fclose(fp);
    return 0;
}