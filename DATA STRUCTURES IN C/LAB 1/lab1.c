#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_AMOUNT_LENGTH 50

typedef struct Expense {
    char data[MAX_CATEGORY_LENGTH][MAX_AMOUNT_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;


void loadExpenses() {
    FILE *file = fopen("Expenses.txt", "r");
    numExpenses = 0;

    if (file == NULL) {
        printf("Error opening the expenses file.\n");
        return;
    }

    char line[1000];

    while (fgets(line, sizeof(line), file) != NULL) {
        char category[MAX_CATEGORY_LENGTH];
        char amount[MAX_AMOUNT_LENGTH];

        if (sscanf(line, "%[^,],%s", category, amount) == 2) {
            if (numExpenses < MAX_EXPENSES) {
                strcpy(expenses[numExpenses].data[0], category);
                strcpy(expenses[numExpenses].data[1], amount);
                numExpenses++;
            } else {
                printf("Expenses list is full. Cannot add more expenses.\n");
            }
        }
    }
    fclose(file);
}

void insertExpense(const char *category, const char *amount) {
    FILE *file = fopen("Expenses.txt", "a");

    if (file == NULL) {
        printf("Error opening the file for appending.\n");
        return;
    }

    fprintf(file, "%s,%s\n", category, amount);
    loadExpenses();
    printf("Expense saved successfully!\n");
    fclose(file);
}

void deleteExpense(char *category) {
    FILE *inputFile = fopen("Expenses.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (inputFile == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char line[1000];
    int found = 0;

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char currentCategory[MAX_CATEGORY_LENGTH];
        char amount[MAX_AMOUNT_LENGTH];

        if (sscanf(line, "%[^,],%s", currentCategory, amount) == 2) {
            if (strcmp(currentCategory, category) == 0) {
                found = 1;
            } else {
                fprintf(tempFile, "%s,%s\n", currentCategory, amount);
            }
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    if (found) {
        remove("Expenses.txt");
        rename("temp.txt", "Expenses.txt");
        printf("Expense in category '%s' deleted successfully.\n", category);
    } else {
        printf("Expense in category '%s' not found in the expense list.\n", category);
        remove("temp.txt");
    }
}

int linearSearch(char *category) {
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].data[0], category) == 0) {
            printf("Expense Found: \nCategory: %s, Amount: %s\n", expenses[i].data[0], expenses[i].data[1]);
            return i;
        }
    }
    printf("Expense in category '%s' not found in the expense list.\n", category);
    return -1;
}

void sortExpensesByAmount() {
    for (int i = 0; i < numExpenses; i++) {
        for (int j = i + 1; j < numExpenses; j++) {
            
            int amount_i = atoi(expenses[i].data[1]);
            int amount_j = atoi(expenses[j].data[1]);

            if (amount_i > amount_j) {
                char tempCategory[MAX_CATEGORY_LENGTH];
                char tempAmount[MAX_AMOUNT_LENGTH];

                strcpy(tempCategory, expenses[i].data[0]);
                strcpy(tempAmount, expenses[i].data[1]);

                strcpy(expenses[i].data[0], expenses[j].data[0]);
                strcpy(expenses[i].data[1], expenses[j].data[1]);

                strcpy(expenses[j].data[0], tempCategory);
                strcpy(expenses[j].data[1], tempAmount);
            }
        }
    }
    printf("Expenses sorted by amount.\n");
}


void matrixMultiplication() {
    int matrix[MAX_EXPENSES][MAX_AMOUNT_LENGTH];

    for (int i = 0; i < numExpenses; i++) {
        for (int j = 0; j < strlen(expenses[i].data[1]); j++) {
            matrix[i][j] = (expenses[i].data[1][j] - '0') * 2;  // Multiplying amount by 2
        }
    }

    printf("Expense Matrix (Amounts multiplied by 2):\n");
    for (int i = 0; i < numExpenses; i++) {
        for (int j = 0; j < strlen(expenses[i].data[1]); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayExpenses() {
    printf("Expense List:\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("Category: %s \t | Amount: %s \t \n", expenses[i].data[0], expenses[i].data[1]);
    }
}


int main() {
    int choice;
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];

    // Loading expenses into memory
    loadExpenses();

    while (1) {
        here:
        printf("\nExpense Tracker\n");
        printf("1. Insert Expense\n");
        printf("2. Delete Expense\n");
        printf("3. Search Expense\n");
        printf("4. Display Expenses\n");
        printf("5. Sort Expenses by Amount\n");
        printf("6. Matrix Multiplication (Amounts multiplied by 2)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter expense category to insert: ");
            scanf("%s", category);
            printf("Enter the amount: ");
            scanf("%s", amount);
            insertExpense(category, amount);
            break;
        case 2:
            printf("Enter expense category to delete: ");
            scanf("%s", category);
            deleteExpense(category);
            break;
        case 3:
            printf("Enter expense category to search: ");
            scanf("%s", category);
            linearSearch(category);
            break;
        case 4:
            displayExpenses();
            break;
        case 5:
            sortExpensesByAmount();
            break;
        case 6:
            matrixMultiplication();
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            goto here;
        }
    }

    return 0;
}
