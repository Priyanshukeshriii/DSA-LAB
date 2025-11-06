#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next ;
};

struct Node* top = NULL;


void addTofirst(int inputdata){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode -> data = inputdata;
    newNode ->next =top; // yiha ye line sa link banta hai and element first mai add hota hai
    top = newNode;
}

void deleteFromFirst(){
    if(top == NULL){
        printf("empty!!");
        return;
    }
    top = top->next;
}

void deleteFromLast(){
    if(top == NULL){
        printf("empty!!");
        return;
    }
    struct Node* temp = top;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
      
}

void deleteFromIndex(int index){
    if(top == NULL){
        printf("empty!!");
        return;
    }
    if(index == 0){
        deleteFromFirst();
        return;
    }
    int count= 0;
    struct Node* temp = top;
    while (temp->next != NULL)
    {
        if(count == index -1){
            temp->next = temp->next->next;
            return;
        }
    }
    
}

void traverse(){
    if(top == NULL){
        printf("underflow");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;// update temp
    }
    printf("\n");
    
}

void deleteAfterData(int value) {
    if (top == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = top;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("No node found after data %d!\n", value);
        return;
    }
    temp->next = temp->next->next;
}

void deleteBeforeData(int value) {
    if (top == NULL || top->next == NULL) {
        printf("No node exists before data %d!\n", value);
        return;
    }

    
    if (top->next->data == value) {
        deleteFromFirst();
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = top;

    while (curr->next != NULL && curr->next->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == NULL) {
        printf("Node with data %d not found!\n", value);
        return;
    }

    
    if (prev != NULL) {
        prev->next = curr->next;
    }
}


int main() {
    int choice, data, index;

    while (1) {
        printf("\n--- Linked List Deletion Menu ---\n");
        printf("1. Add to First\n");
        printf("2. Delete from First\n");
        printf("3. Delete from Last\n");
        printf("4. Delete from Index\n");
        printf("5. Delete After Data\n");
        printf("6. Delete Before Data\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addTofirst(data);
                break;

            case 2:
                deleteFromFirst();
                break;

            case 3:
                deleteFromLast();
                break;

            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteFromIndex(index);
                break;

            case 5:
                printf("Enter data value (delete node AFTER this): ");
                scanf("%d", &data);
                deleteAfterData(data);
                break;

            case 6:
                printf("Enter data value (delete node BEFORE this): ");
                scanf("%d", &data);
                deleteBeforeData(data);
                break;

            case 7:
                traverse();
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
