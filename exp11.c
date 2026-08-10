#include <stdio.h>
#include <string.h>
struct Symbol {
    char name[20];
    char type[20];
    char value[20];
};
struct Symbol table[50];
int count = 0;
void insert() {
    char name[20];
    printf("Enter symbol name: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol already exists!\n");
            return;
        }
    }
    strcpy(table[count].name, name);
    printf("Enter type: ");
    scanf("%s", table[count].type);
    printf("Enter value: ");
    scanf("%s", table[count].value);
    count++;
    printf("Symbol inserted successfully.\n");
}
void search() {
    char name[20];
    printf("Enter symbol to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol found!\n");
            printf("Name  : %s\n", table[i].name);
            printf("Type  : %s\n", table[i].type);
            printf("Value : %s\n", table[i].value);
            return;
        }
    }
    printf("Symbol not found.\n");
}
void display() {
    printf("\nSymbol Table\n");
    printf("--------------------------------\n");
    printf("Name\tType\tValue\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++)
        printf("%s\t%s\t%s\n",
               table[i].name,
               table[i].type,
               table[i].value);
}
void deleteSymbol() {
    char name[20];
    printf("Enter symbol to delete: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++)
                table[j] = table[j + 1];
            count--;
            printf("Symbol deleted successfully.\n");
            return;
        }
    }
    printf("Symbol not found.\n");
}
int main() {
    int choice;
    do {
        printf("\n--- SYMBOL TABLE ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                deleteSymbol();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}