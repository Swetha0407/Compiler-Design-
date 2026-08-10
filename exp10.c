#include <stdio.h>
#include <string.h>
int main() {
    char p1[50], p2[50], p3[50];
    char prefix[50], rem1[50], rem2[50];
    int i, j = 0;
    printf("Enter productions of S:\n");
    scanf("%s", p1);
    scanf("%s", p2);
    scanf("%s", p3);
    /* Find common prefix of first two productions */
    for (i = 0; p1[i] != '\0' && p2[i] != '\0'; i++) {
        if (p1[i] == p2[i])
            prefix[j++] = p1[i];
        else
            break;
    }
    prefix[j] = '\0';
    /* Find remaining parts */
    strcpy(rem1, p1 + i);
    strcpy(rem2, p2 + i);
    printf("\nCommon prefix = %s\n", prefix);
    printf("\nAfter eliminating left factoring:\n");
    printf("S  -> %sS' | %s\n", prefix, p3);
    printf("S' -> %sS | %s\n", rem1, rem2);
    return 0;
}