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
    
}

int main(){
    addTofirst(39);
    addTofirst(3);
    addTofirst(9);
    addTofirst(339);
    triverse();
    return 0;
}