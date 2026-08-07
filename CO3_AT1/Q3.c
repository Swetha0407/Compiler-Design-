#include <stdio.h>
#include <ctype.h>
char input[100];
int pos = 0;
int E();
int T();
int F();
int E() {
    int value = T();
    while(input[pos] == '+') {
        pos++;
        value = value + T();
    }
    return value;
}
int T() {
    int value = F();
    while(input[pos] == '*') {
        pos++;
        value = value * F();
    }
    return value;
}
int F() {
    int value = 0;
    while(isdigit(input[pos])) {
        value = value * 10 + (input[pos] - '0');
        pos++;
    }
    return value;
}
int main() {
    printf("Enter expression (Example: 2+3*4): ");
    scanf("%s", input);
    printf("Result = %d\n", E());
    return 0;
}