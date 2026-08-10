#include <stdio.h>
#include <string.h>
#include <ctype.h>
char prod[10][20];
int n;
void FIRST(char c) {
    int i, j;
    if (!isupper(c)) {
        printf("%c ", c);
        return;
    }
    for (i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            for (j = 2; prod[i][j] != '\0'; j++) {
                if (prod[i][j] == 'e') {
                    printf("e ");
                    break;
                }
                if (!isupper(prod[i][j])) {
                    printf("%c ", prod[i][j]);
                    break;
                }
                FIRST(prod[i][j]);
                break;
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
    printf("\nEnter the non-terminal to find FIRST: ");
    scanf(" %c", &c);
    printf("FIRST(%c) = { ", c);
    FIRST(c);
    printf("}\n");
    return 0;
}