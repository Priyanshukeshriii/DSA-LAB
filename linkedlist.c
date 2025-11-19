#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void addTofirst(int inputdata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = inputdata;
    newNode->next = top;
    top = newNode;
    printf("done!");
}


void traverse() {
    if (top == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = top;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void addToEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (top == NULL) {
        top = newNode;
        return;
    }

    struct Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void addAfterData(int newData, int existingData) {
    struct Node* temp = top;

    while (temp != NULL && temp->data != existingData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found!\n", existingData);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d\n", newData, existingData);
}


void addBeforeData(int newData, int existingData) {
    if (top == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If inserting before the first node
    if (top->data == existingData) {
        addTofirst(newData);
        printf("Inserted %d before %d\n", newData, existingData);
        return;
    }

    struct Node* temp = top;
    while (temp->next != NULL && temp->next->data != existingData) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with data %d not found!\n", existingData);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d before %d\n", newData, existingData);
}

// Main program
int main() {
    int choice, data, existing;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Add to First\n");
        printf("2. Add to End\n");
        printf("3. Add After Data\n");
        printf("4. Add Before Data\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at first: ");
                scanf("%d", &data);
                addTofirst(data);
                break;

            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                addToEnd(data);
                break;

            case 3:
                printf("Enter new data to insert: ");
                scanf("%d", &data);
                printf("Enter existing data after which to insert: ");
                scanf("%d", &existing);
                addAfterData(data, existing);
                break;

            case 4:
                printf("Enter new data to insert: ");
                scanf("%d", &data);
                printf("Enter existing data before which to insert: ");
                scanf("%d", &existing);
                addBeforeData(data, existing);
                break;

            case 5:
                traverse();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
