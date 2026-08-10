#include <stdio.h>
#include <string.h>
int main() {
    char nt, prod[10][50];
    int n, i, j = 0;
    printf("Enter non-terminal: ");
    scanf(" %c", &nt);
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions:\n");
    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);
    printf("\nAfter eliminating left recursion:\n");
    for (i = 0; i < n; i++) {
        if (prod[i][0] == nt)
            j = i;
    }
    if (prod[j][0] == nt) {
        printf("%c -> ", nt);
        for (i = 0; i < n; i++) {
            if (prod[i][0] != nt)
                printf("%s%c' | ", prod[i], nt);
        }
        printf("\n%c' -> ", nt);
        for (i = 0; i < n; i++) {
            if (prod[i][0] == nt)
                printf("%s%c' | ", prod[i] + 1, nt);
        }
        printf("e\n");
    }
    return 0;
}