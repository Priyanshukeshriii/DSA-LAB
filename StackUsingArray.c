#include<stdio.h>
#define MAX_DATA  10
int stack[MAX_DATA] ;
int top = -1;

void push(){    
    if(top == MAX_DATA -1){
        printf("Overflow\n");
    }else{
        int data;
        printf("Enter the value: \n");
        scanf("%d" ,&data);
        stack[++top] = data;
        printf("Done!!\n");
    }
}

int pop(){
    if(top == -1){
        printf("underflow\n");
        
        
    }else{
        
        printf("the value is %d\n",stack[top]);
        return stack[top--];
    }
}

void peek(){
    if(top == -1){
        printf("underflow\n");
    }else{
        printf("the top is %d\n", stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("underflow\n");
    }else{
        for(int i = top ; i >= 0; i++){
            printf("the value element is: %d\n",stack[i]);
        }
    }
}
void createStack(){
    top = -1;
    printf("created\n");
}


int main(){
    int choice;
    int a = 1;
    while (a) {
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
            case 3: printf("%d\n",pop()); break;
            case 4: peek(); break;
            case 5: display(); break;
            case 6: a=0; break;
            default: printf("Invalid choice! Try again.\n");
        }
    }

}