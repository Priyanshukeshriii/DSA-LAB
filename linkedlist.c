#include<stdio.h>
#include<stdlib.h>
#define max 10
struct Node
{
    int data;
    struct Node* next ;//by default  null
};

struct Node* top = NULL;

void addTofirst(int inputdata){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode -> data = inputdata;
    newNode ->next =top; // yiha ye line sa link banta hai and element first mai add hota hai
    top = newNode;
}

void triverse(){
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

void addToEnd(int data){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode -> data = data;
    struct Node* temp = top;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    
}

void addAfterAnIndex(int data, int pos){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode -> data = data;
    int count = 0;
    struct Node* temp = top;
    while (temp->next != NULL){
        if(count == pos){
            break;
        }
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}
void addAtAnIndex(int data, int pos){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode -> data = data;
    int count = 0;
    if(pos == 0){
        newNode->next = top;
        top = newNode;
        
    }
    else
    {
        struct Node* temp = top;
        while (temp->next != NULL){
            if(count == pos-1){
                break;
            }
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
}
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Add to First\n");
        printf("2. Add to End\n");
        printf("3. Add After Index\n");
        printf("4. Add at Index\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
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
                addToEnd(data);
                break;

            case 3:
                printf("Enter data and index: ");
                scanf("%d %d", &data, &pos);
                addAfterAnIndex(data, pos);
                break;

            case 4:
                printf("Enter data and index: ");
                scanf("%d %d", &data, &pos);
                addAtAnIndex(data, pos);
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