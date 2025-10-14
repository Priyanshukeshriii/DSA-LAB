#include <stdio.h>

#define Max 10

typedef struct {
    int data;
    int priority;
} Node;

Node pq[Max];
int size = 0;

void enqueue(int data, int priority) {
    if (size == Max) {
        printf("Overflow\n");
        return;
    }

    int i = size - 1;
    
    while (i >= 0 && pq[i].priority > priority) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    size++;

    printf("Enqueued: data=%d, priority=%d\n", data, priority);
}

int dequeue() {
    if (size == 0) {
        printf("Underflow\n");
        return -1;
    }

    int data = pq[0].data;
    printf("Dequeued: data=%d, priority=%d\n", pq[0].data, pq[0].priority);

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
    return data;
}

void display() {
    if (size == 0) {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("\nPriority Queue Elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Data: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

int main() {
    int choice, data, priority;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority : ");
                scanf("%d", &priority);
                enqueue(data, priority);
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

