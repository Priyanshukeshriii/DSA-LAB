
// Linear queue with menu-based operations: Enqueue, Dequeue, and Display.
#include<stdio.h>
#include <limits.h>
#define MAX 20
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(rear == MAX -1){
        printf("overFlow!!");
    }else{
        if(front == -1){
            front = 0;
        }
        queue[++rear] = data;
    }
}
int dequeue(){
    if(front == -1 || front > rear){
        printf("Under Flow!!");
        return INT_MIN;
    }else{
        return queue[front++];
    }
}

void display(){
    if(front == -1){
        printf("Under Flow!!");
    }
    else{
        for(int  i = front ; i < rear ; i++){
            printf("%d, ", queue[i]);
        }
        printf("\n");
    }
}


int main(){
    int choice, data, val;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                val = dequeue();
                if (val != INT_MIN) {
                    printf("Dequeued: %d\n", val);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}