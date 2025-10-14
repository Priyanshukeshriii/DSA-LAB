#include <stdio.h>
#define MAX 20

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
