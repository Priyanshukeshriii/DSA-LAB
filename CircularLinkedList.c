#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void addToFirst(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof (struct Node));
    newNode->data = data;
    if(last == NULL){
        last = newNode;
        last->next = last;
    }else{
        newNode->next = last->next;
        last->next = newNode;
    }
}

void addToLast(int data){
    struct Node* newNode  = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = data;
    if(last == NULL){
        last = newNode;
        last->next = last;
    }else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    
}

void addToIndex(int data, int index){
    struct Node* newNode  = (struct Node*) malloc (sizeof(struct Node));
    newNode->data =data;
    if(last == NULL){
        last = newNode;
        last->next = last;
    }else{
        struct Node* temp  = last->next;//start from first
        int count = 0;
        while (count < index - 1 && temp != last)
        {
            count++;
            temp = temp->next;
        }
       if(count == index-1)
       {
         newNode->next = temp->next;
        temp->next = newNode;
        if(temp == last){
            last = newNode;
        }
    }
    else{
        printf("out of index!! data is not added");
    }
    }
}

void deleteFromfirst(){
    if(last == NULL){
        printf("Linked List is Empty!");
        return;
    }
    if(last == last->next){
        printf("%d is deleted",last->data);
        last = NULL;
    }else{
        printf("%d is deleted",last->next->data);
        last->next = last->next->next;
    }
}

void deleteFromlast(){
    if(last == NULL){
        printf("Linked List is Empty!");
        return;
    }
    struct Node* temp = last->next;//pointing to first
    if(last == last->next){
        printf("%d is deleted",last->data);
        last = NULL;
    }
    else{
        while (temp->next != last)
        {
            temp = temp->next;
        }
        printf("%d is deleted",last->data);
        temp->next = last->next;
        last = temp;
    }

}

void deleteFromIndex(int index) {
    if (last == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }

    
    if (last == last->next) {
        printf("%d is deleted\n", last->data);
        
        last = NULL;
        return;
    }

    
    if (index == 0) {
        deleteFromfirst();
        return;
    }

    struct Node* temp = last->next;
    int count = 0;

    
    while (count < index - 1 && temp->next != last->next) {
        temp = temp->next;
        count++;
    }

    
    if (temp->next == last->next) {
        printf("Invalid index!\n");
        return;
    }

    
    struct Node* delNode = temp->next;

    
    if (delNode == last) {
        deleteFromlast();
        return;
    }

    
    temp->next = delNode->next;
    printf("%d is deleted\n", delNode->data);
    
}
                                                                
void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
}

int main() {
    int choice, data, index;

    while (1) {
        printf("\n===== Circular Linked List Menu =====\n");
        printf("1. Add to First\n");
        printf("2. Add to Last\n");
        printf("3. Add at Index\n");
        printf("4. Delete from First\n");
        printf("5. Delete from Last\n");
        printf("6. Delete from Index\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
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
                addToLast(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter index: ");
                scanf("%d", &index);
                addToIndex(data, index);
                break;

            case 4:
                deleteFromfirst();
                printf("\n");
                break;

            case 5:
                deleteFromlast();
                printf("\n");
                break;

            case 6:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteFromIndex(index);
                printf("\n");
                break;

            case 7:
                display();
                printf("\n");
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
