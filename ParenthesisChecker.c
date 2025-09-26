#include<stdio.h>
#include<limits.h>


#define MAX 20
char stack [MAX];
int top =-1;

void push(char data ){
    if(top == MAX -1){
        printf("overflow\n");
    }
    else{
        stack[++top] = data;
    }
}

int pop(){
    if(top == -1){
        printf("underflow\n");
        return INT_MIN;
    }
    else{
        return stack[top--];
    }
}

parenthesisChecker(char exp){
    int check = 0;
    char *x;
    char *e = exp;
    while (*e != '\0')
    {
        if(*e == '(' || *e == '{' || *e == '['){
            push(*e);

        }
        if(*e == ')' || *e == '}' || *e == ']'){
            while ((x = pop()) != *e);
            {
                /* code */
            }
            
        }
    }
    

}
int main(){
    char experssion[MAX];
    printf("Enter experssion: ");
    scanf("%s", experssion);

}