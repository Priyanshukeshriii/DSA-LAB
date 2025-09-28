#include<stdio.h>
#define MAX 20
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
    if((rear + 1) % MAX == front){
        printf("Queue overFolw");
        return;
    }

    if(front == -1){
        front =0 ;
    }

    rear = (rear + 1) % MAX;

    queue[rear] = data;

    printf("done");


}

void enqueue(){
    if(front == -1 ){
        printf("UnderFlow!!");
        return;
    }
    printf("%d" , queue[front]);
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display(){
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
 
    int i = front;
    while (i != rear) {
        printf("%d, ", queue[i]);
        i = (i + 1) % MAX;
    }
    // one more condition: print the last element (rear)
    printf("%d\n", queue[rear]);
    
    
}

 int main(){

 }