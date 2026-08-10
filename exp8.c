#include <stdio.h>
#include <string.h>
#include <ctype.h>
char prod[10][20];
int n;
void FOLLOW(char c) {
    int i, j;
    if (c == prod[0][0])
        printf("$ ");
    for (i = 0; i < n; i++) {
        for (j = 2; prod[i][j] != '\0'; j++) {
            if (prod[i][j] == c) {
                if (prod[i][j + 1] != '\0') {
                    if (!isupper(prod[i][j + 1]))
                        printf("%c ", prod[i][j + 1]);
                }
            }
        }
    }
}

int main() {
    int i;
    char c;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (use e for epsilon):\n");
    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);
    printf("\nEnter the non-terminal to find FOLLOW: ");
    scanf(" %c", &c);
    printf("FOLLOW(%c) = { ", c);
    FOLLOW(c);
    printf("}\n");
    return 0;
}