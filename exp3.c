#include<stdio.h>

int main()
{
    FILE *fp=fopen("inputexp3.txt","r");
    char ch,next,prev=0;

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch==' '||ch=='\t'||ch=='\n')
            continue;

        if(ch=='/')
        {
            next=fgetc(fp);

            if(next=='/')
            {
                while((ch=fgetc(fp))!='\n'&&ch!=EOF);
            }
            else if(next=='*')
            {
                while((ch=fgetc(fp))!=EOF)
                {
                    if(prev=='*'&&ch=='/')
                        break;
                    prev=ch;
                }
            }
            else
            {
                printf("%c",ch);
                ungetc(next,fp);
            }
        }
        else
            printf("%c",ch);
    }

    fclose(fp);
    return 0;
}