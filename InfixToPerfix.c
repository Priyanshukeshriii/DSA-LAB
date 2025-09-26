// 2. Conversion of an Infix to a Prefix (using stacks)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100
char stack[MAX];
int top = -1;

// Stack functions
void push(char c) {
    if(top == MAX -1){
        printf("overflow");
        return '\0';
    }
    stack[++top] = c;
}
char pop() {
    if(top == -1){
        printf("underflow");
        return '\0';
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// Operator precedence
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

// Reverse a string
void reverse(char exp[]) {
    int n = strlen(exp);
    for (int i = 0; i < n/2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;  // Operand → directly output
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else { // Operator
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Step 1: Reverse infix
    reverse(infix);

    // Step 2: Swap brackets
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Get postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse postfix → prefix
    strcpy(prefix, postfix);
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

