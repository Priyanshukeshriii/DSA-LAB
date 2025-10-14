#include <stdio.h>
#include <limits.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char data) {
    if (top == MAX - 1) {
        printf("Overflow\n");
    } else {
        stack[++top] = data;
    }
}

char pop() {
    if (top == -1) {
        return '\0'; 
    } else {
        return stack[top--];
    }
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

void parenthesisChecker(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            char x = pop();
            if (!isMatchingPair(x, c)) {
                printf("Unbalanced expression ❌\n");
                return;
            }
        }
    }

    if (top == -1)
        printf("Balanced expression \n");
    else
        printf("Unbalanced expression \n");
}

int main() {
    char expression[MAX];
    printf("Enter expression: ");
    scanf("%s", expression);

    parenthesisChecker(expression);
    return 0;
}
