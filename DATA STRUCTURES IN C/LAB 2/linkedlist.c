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

ExpenseNode* insertExpense(const char* category, float amount) {
    ExpenseNode* newNode = createExpenseNode(category, amount);
    newNode->next = HEAD;
    HEAD = newNode;
    return newNode;
}

ExpenseNode* deleteExpense(const char* category) {
    ExpenseNode* current = HEAD;
    ExpenseNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->category, category) == 0) {
            if (prev == NULL) {
                HEAD = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return HEAD;
        }

        prev = current;
        current = current->next;
    }

    printf("Expense under category '%s' not found.\n", category);
    return HEAD;
}

void searchExpenseByCategory(const char* category) {
    ExpenseNode* current = HEAD;
    while (current != NULL) {
        if (strcmp(current->category, category) == 0) {
            printf("Expense Found: Category: %s, Amount: %.2f\n", current->category, current->amount);
            return;
        }
        current = current->next;
    }
    printf("No expense found under category '%s'.\n", category);
}

void displayExpenses() {
    ExpenseNode* current = HEAD;
    if (current == NULL) {
        printf("Expense list is empty.\n");
        return;
    }

    printf("Expenses:\n");
    while (current != NULL) {
        printf("Category: %s \t  \t Amount: %.2f\n", current->category, current->amount);
        current = current->next;
    }
}

void freeExpenses() {
    ExpenseNode* current = HEAD;
    while (current != NULL) {
        ExpenseNode* next = current->next;
        free(current);
        current = next;
    }
}

void loadExpenses() {
    FILE *file = fopen("Expenses.txt", "r");

    if (file == NULL) {
        printf("Error opening the expenses file.\n");
        return;
    }

    char line[1000];

    while (fgets(line, sizeof(line), file) != NULL) {
        char category[MAX_CATEGORY_LENGTH];
        float amount;

        if (sscanf(line, "%[^,],%f", category, &amount) == 2) {
            insertExpense(category, amount);
        }
    }

    printf("Expenses list is loaded into the memory.\n");

    fclose(file);
}

int main() {
    ExpenseNode* expenseList = NULL;
    int choice;
    char category[MAX_CATEGORY_LENGTH];
    float amount;

    loadExpenses();

    while (1) {
        printf("\nExpense Tracker (Singly Linked List)\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense using category\n");
        printf("3. Search Expense using category\n");
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
                expenseList = insertExpense(category, amount);
                break;
            case 2:
                printf("Enter expense category to delete: ");
                scanf("%s", category);
                expenseList = deleteExpense(category);
                break;
            case 3:
                printf("Enter category to search: ");
                scanf("%s", category);
                searchExpenseByCategory(category);
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
