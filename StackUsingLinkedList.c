#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next ;    
};

struct Node* top = NULL;

void push(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    if(newNode == NULL){
        printf("Stack overflow (memory not available))\n");
        return ;
    }
    newNode -> data = data;
    newNode ->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("stack underflow (stack is empty))");
        return;
    }
    printf("%d",top->data);
    top = top->next;
}

void peek(){
    if(top == NULL){
        printf("stack is empty");
    }
    else{
        printf("top element is %d\n", top->data);
    }
}

void display(){

    if(top == NULL){
        printf("stack is empty");
    }
    struct Node* temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    free(temp);
    
}

int main(){
     int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}