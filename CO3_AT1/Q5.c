#include <stdio.h>
#include <string.h>
int main() {
    char type1[20], type2[20], op;
    printf("Enter first operand type: ");
    scanf("%s", type1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter second operand type: ");
    scanf("%s", type2);
    if ((strcmp(type1, "int") == 0 || strcmp(type1, "float") == 0) &&
        (strcmp(type2, "int") == 0 || strcmp(type2, "float") == 0))
        printf("\nValid Expression\n");
    else
        printf("\nType Error\n");
    return 0;
}