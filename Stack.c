#include <stdio.h>
#include <stdlib.h>

#define MAX 100   

int stack[MAX];
int top = -1;    


void createStack() {
    top = -1; 
    printf("Stack created successfully.\n");
}


void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}


void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Create new Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
