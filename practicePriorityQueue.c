#include<stdio.h>

#define Max 10

typedef struct {
    int data ;
    int priority;
}Node;

Node pq[10];
int size = 0;

void enqueue(int data , int priority){
    if(size == Max -1){
        printf("overflow");
        return;
    }
    int i = size -1;
    while (i >=0 && pq[i].priority > priority)
    {
        pq[i+1] = pq[i];
        i--;
    }
    pq[i+1].data = data;
    pq[i+1].priority =priority;
    size++;
    
} 

int dequeue(){
    if(size ==0 ){
        printf("underflow");
        return ;
    }
    printf("data %d priority : %d" , pq[0].data , pq[0].priority);
    int data = pq[0].data ;
    for(int i = 1 ; i< size; i++){
        pq[i-1] = pq[i];
    } 
    size--;
    return data;
}

void display() {
    if(size == 0) {
        printf("Priority Queue is Empty!\n");
        return;
    }
    printf("Priority Queue Elements:\n");
    for(int i = 0; i < size; i++) {
        printf("Data: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}