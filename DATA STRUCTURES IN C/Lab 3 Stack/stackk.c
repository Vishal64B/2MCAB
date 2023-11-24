#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp);
int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
void push(struct stack *ptr, char val);
char pop(struct stack *ptr);
int precedence(char ch);
int isOperator(char ch);
char *infixToPostfix(char *infix);

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}


int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1);
}

int isFull(struct stack *ptr)
{
    return (ptr->top == ptr->size - 1);
}


void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}


int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}


void displayPostfix(char *postfix)
{
    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[100];
    char *postfix;

    int choice;
    do
    {
        printf("\n------Menu------:\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Display Postfix Expression\n");
        printf("3. Close\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Infix Expression: ");
            scanf("%s", infix);
            postfix = infixToPostfix(infix);
            break;
        case 2:
            if (postfix != NULL)
                displayPostfix(postfix);
            else
                printf("No postfix expression entered yet!\n");
            break;
        case 3:
            printf("Closing the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    free(postfix); 
    return 0;
}
