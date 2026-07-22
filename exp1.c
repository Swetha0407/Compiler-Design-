#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() {
    FILE *fp=fopen("input.txt","r");
    char ch,s[50],p;
    int i;
    while((ch=fgetc(fp))!=EOF) {
        if(ch==' '||ch=='\n'||ch=='\t')
            continue;
        if(ch=='/') {
            p=fgetc(fp);
            if(p=='/') 
                while((ch=fgetc(fp))!='\n'&&ch!=EOF);
            else if(p=='*') {
                char x=0;
                while((ch=fgetc(fp))!=EOF) {
                    if(x=='*'&&ch=='/')
                        break;
                    x=ch;
                }
            }
            else  {
                printf("Operator : /\n");
                ungetc(p,fp);
            }
        }
        else if(isalpha(ch)||ch=='_') {
            i=0;
            do s[i++]=ch;
            while(isalnum(ch=fgetc(fp))||ch=='_');
            s[i]='\0';
            printf("Identifier : %s\n",s);
            ungetc(ch,fp);
        }
        else if(isdigit(ch)) {
            i=0;
            do s[i++]=ch;
            while(isdigit(ch=fgetc(fp)));
            s[i]='\0';
            printf("Constant : %s\n",s);
            ungetc(ch,fp);
        }
        else if(strchr("+-*=<>!%",ch))
            printf("Operator : %c\n",ch);
    }
    fclose(fp);
    return 0;
}