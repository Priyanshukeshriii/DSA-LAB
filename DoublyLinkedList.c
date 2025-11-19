#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

struct Node* head = NULL;


void addToFirst(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->previous = newNode;
    }
    head = newNode;
}

void addAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->previous = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->previous = temp;
}

void addAfterData(int newdata, int olddata) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != olddata) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data %d not found!\n", olddata);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newdata;
    newNode->next = temp->next;
    newNode->previous = temp;

    if (temp->next != NULL) {
        temp->next->previous = newNode;
    }
    temp->next = newNode;
}

void addBeforeData(int newdata, int olddata) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

   
    if (head->data == olddata) {
        addToFirst(newdata);
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL && temp->next->data != olddata) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Data %d not found!\n", olddata);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newdata;
    newNode->next = temp->next;
    newNode->previous = temp;
    temp->next->previous = newNode;
    temp->next = newNode;
}

void addAtIndex(int index, int data) {
    if (index < 0) {
        printf("Invalid index!\n");
        return;
    }

    if (index == 0) {
        addToFirst(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    struct Node* temp = head;
    int i = 0;

    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range! Adding at end.\n");
        addAtEnd(data);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->previous = temp;
    if (temp->next != NULL)
        temp->next->previous = newNode;
    temp->next = newNode;

    printf("%d added at index %d.\n", data, index);
}


void deleteFromFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->previous = NULL;
    }
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->previous->next = NULL;
    free(temp);
}

void deleteBeforeValue(int value) {
    if (head == NULL || head->next == NULL) {
        printf("Not enough nodes to delete before %d.\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->previous == NULL) {
        printf("No node exists before %d.\n", value);
        return;
    }

    struct Node* del = temp->previous;
    if (del->previous != NULL)
        del->previous->next = temp;
    else
        head = temp;  

    temp->previous = del->previous;
    free(del);
}

void deleteAfterValue(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after %d.\n", value);
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    if (del->next != NULL)
        del->next->previous = temp;
    free(del);
}

void deleteAtIndex(int index) {
    if (head == NULL || index < 0) {
        printf("Invalid index or empty list!\n");
        return;
    }

    struct Node* temp = head;
    int i = 0;

    
    if (index == 0) {
        deleteFromFirst();
        return;
    }

    while (temp != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        return;
    }

    temp->previous->next = temp->next;
    if (temp->next != NULL)
        temp->next->previous = temp->previous;
    free(temp);
}

void deleteAllOccurrences(int data){
    struct Node* temp = head;
    while (temp != NULL)
    {
        if(temp->data == data){
            if(temp->previous != NULL){
                temp->previous->next = temp->next;
            }else{
                head = temp->next;
            }
            temp = temp->next;
        }
        else {
            temp = temp->next;
        }

    }
    
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, data, olddata, index;

    while (1) {
        printf("1. Add to First\n");
        printf("2. Add to End\n");
        printf("3. Add After Value\n");
        printf("4. Add Before Value\n");
        printf("5. Add at Index\n");
        printf("6. Delete from First\n");
        printf("7. Delete from End\n");
        printf("8. Delete Before Value\n");
        printf("9. Delete After Value\n");
        printf("10. Delete by Index\n");
        printf("11. Delete All Occurrences\n");
        printf("12. Display\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addToFirst(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addAtEnd(data);
                break;

            case 3:
                printf("Enter new data: ");
                scanf("%d", &data);
                printf("Enter existing data: ");
                scanf("%d", &olddata);
                addAfterData(data, olddata);
                break;

            case 4:
                printf("Enter new data: ");
                scanf("%d", &data);
                printf("Enter existing data: ");
                scanf("%d", &olddata);
                addBeforeData(data, olddata);
                break;

            case 5:
                printf("Enter index and data: ");
                scanf("%d %d", &index, &data);
                addAtIndex(index, data);
                break;

            case 6:
                deleteFromFirst();
                break;

            case 7:
                deleteFromEnd();
                break;

            case 8:
                printf("Enter value: ");
                scanf("%d", &data);
                deleteBeforeValue(data);
                break;

            case 9:
                printf("Enter value: ");
                scanf("%d", &data);
                deleteAfterValue(data);
                break;

            case 10:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteAtIndex(index);
                break;

            case 11:
                printf("Enter value to delete all occurrences: ");
                scanf("%d", &data);
                deleteAllOccurrences(data);
                break;

            case 12:
                display();
                break;

            case 13:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}