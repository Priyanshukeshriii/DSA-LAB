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

int main() {
    addTofirst(10);
    addTofirst(20);
    addTofirst(30);
    addTofirst(40);
    printf("After adding elements:\n");
    traverse();

    deleteFromFirst();
    printf("\nAfter deleting first element:\n");
    traverse();

    deleteFromLast();
    printf("\nAfter deleting last element:\n");
    traverse();

    deleteFromIndex(1);
    printf("\nAfter deleting element at index 1:\n");
    traverse();

    deleteFromIndex(5);
    printf("\nAfter trying to delete invalid index:\n");
    traverse();

    return 0;
}
