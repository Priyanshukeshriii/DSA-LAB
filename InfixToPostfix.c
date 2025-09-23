#include<stdio.h>
#include<ctype.h>

#define MAX_DATA  30
char stack[MAX_DATA] ;
int top = -1;

void push(char ch){    
    if(top == MAX_DATA -1){
    }else{
        stack[++top] = ch;
    }
}

int pop(){
    if(top == -1){
        return '\0';
        
    }else{
        return stack[top--];
    }
}

int priority(char ch ){
    if(ch == '+' || ch == '-'){
        return 0;
    }
    if(ch == '*' || ch == '/'){
        return 1;
    }
    return 2;
}

int main(){
    char exp[30];
    char *e ,x;
    printf("enter the expersion :");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0'){
        if(isalnum(*e)){
        printf("%c",*e);
        }
        else if(*e == '('){
            push(*e);
        }
        else if(*e == ')'){
            while ((x=pop()) != '(' )
            {
                printf("%c", x);
            }
            
        }
        else{
            while (priority(*e)>=priority(stack[top]))
            {
                printf("%c",pop());
            }
            push(*e);
            
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c",pop());
    }
    
}