#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORY_LENGTH 50

struct ExpenseNode {
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    struct ExpenseNode* next;
};

typedef struct ExpenseNode ExpenseNode;

ExpenseNode *HEAD;

ExpenseNode* createExpenseNode(const char* category, float amount) {
    ExpenseNode* newNode = (ExpenseNode*)malloc(sizeof(ExpenseNode));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->category, category, MAX_CATEGORY_LENGTH - 1);
    newNode->category[MAX_CATEGORY_LENGTH - 1] = '\0';

    newNode->amount = amount;

    newNode->next = NULL;
    return newNode;
}

ExpenseNode* insertExpense(const char* category, float amount, int position) {
    ExpenseNode* newNode = createExpenseNode(category, amount);

    if (HEAD == NULL) {
        HEAD = newNode;
        newNode->next = HEAD; // Circular reference to itself
    } else {
        ExpenseNode* current = HEAD;
        int currentPosition = 1;

        while (currentPosition < position - 1 && current->next != HEAD) {
            current = current->next;
            currentPosition++;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (position == 1) {
            HEAD = newNode;
        }
    }

    return HEAD;
}

ExpenseNode* deleteExpense(const char* category) {
    ExpenseNode* current = HEAD;
    ExpenseNode* prev = NULL;

    if (current == NULL) {
        printf("Expense list is empty.\n");
        return HEAD;
    }

    do {
        if (strcmp(current->category, category) == 0) {
            if (current == HEAD) {
                HEAD = current->next;
            }

            if (prev != NULL) {
                prev->next = current->next;
            }

            free(current);
            return HEAD;
        }

        prev = current;
        current = current->next;
    } while (current != HEAD);

    printf("Expense category '%s' not found.\n", category);
    return HEAD;
}

void searchExpense(const char* category) {
    ExpenseNode* current = HEAD;

    if (current == NULL) {
        printf("Expense list is empty.\n");
        return;
    }

    do {
        if (strcmp(current->category, category) == 0) {
            printf("Expense Found: Category: %s, Amount: %.2f\n", current->category, current->amount);
            return;
        }
        current = current->next;
    } while (current != HEAD);

    printf("Expense category '%s' not found.\n", category);
}

void displayExpenses() {
    ExpenseNode* current = HEAD;

    if (current == NULL) {
        printf("Expense list is empty.\n");
        return;
    }

    printf("Expenses:\n");
    do {
        printf("Category: %s \t\t Amount: %.2f\n", current->category, current->amount);
        current = current->next;
    } while (current != HEAD);
}

void freeExpenses() {
    ExpenseNode* current = HEAD;
    ExpenseNode* temp;

    if (current == NULL) {
        return;
    }

    do {
        temp = current->next;
        free(current);
        current = temp;
    } while (current != HEAD);

    HEAD = NULL;
}

void loadExpenses() {
    FILE* file = fopen("Expenses.txt", "r");

    if (file == NULL) {
        printf("Error opening the expenses file.\n");
        return;
    }

    char line[1000];
    int pos = 0; // By default, insert at the start

    while (fgets(line, sizeof(line), file) != NULL) {
        char category[MAX_CATEGORY_LENGTH];
        float amount;

        if (sscanf(line, "%[^,],%f", category, &amount) == 2) {
            insertExpense(category, amount, pos);
        }
    }

    printf("Expenses list is loaded into the memory.\n");

    fclose(file);
}

int main() {
    int choice;
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    int pos = 0;

    loadExpenses();

    while (1) {
        printf("\nExpense Tracker (Circular Linked List)\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense\n");
        printf("3. Search Expense\n");
        printf("4. Display Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter the amount: ");
                scanf("%f", &amount);
                printf("Enter the position: ");
                scanf("%d", &pos);
                HEAD = insertExpense(category, amount, pos);
                break;
            case 2:
                printf("Enter expense category to delete: ");
                scanf("%s", category);
                HEAD = deleteExpense(category);
                break;
            case 3:
                printf("Enter expense category to search: ");
                scanf("%s", category);
                searchExpense(category);
                break;
            case 4:
                displayExpenses();
                break;
            case 5:
                freeExpenses();
                printf("Exiting the program!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
