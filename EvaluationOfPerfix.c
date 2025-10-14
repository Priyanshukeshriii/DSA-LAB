#include<stdio.h>
#include <string.h>
#include<limits.h>
#include<math.h>
#include<ctype.h>

#define MAX 30


int top = -1;
void push(int data , int stack[]){
    if(top == MAX -1){
        printf("overflow\n");
    }
    else{
        stack[++top] = data;
    }
}

int pop(int stack[]){
    if(top == -1){
        printf("underflow\n");
        return INT_MIN;
    }
    else{
        return stack[top--];
    }
}

int isEmpty(){
    return top == -1;
}

int operation(int a , int b , char operator){
    switch (operator)
    {
    case '+': return a+b; break;
    case '-': return a -b ;break;
    case '*': return a*b; break;
    case '/': if (b == 0) {
                printf("Division by zero!\n");
                return INT_MIN;
                }
                return a/b ; break;
    case '^': return (int)pow(a,b); break;
    
    default:
        printf("Invalid operator %c\n", operator);
        return INT_MIN;
    }
}

int prefixChecker(char prefix[]){
    int stack[MAX];
    top =-1;
    for(int i = strlen(prefix) -1; i >= 0; i--){
        
        if(prefix[i] == ' '){
            continue;
        }
        if(prefix[i] == '\0'){
            continue;
        }
        if(isdigit(prefix[i])){


            push(prefix[i] -'0',stack);
        }
        else if (prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/'||prefix[i]=='^') {
            int op1 = pop(stack);
            int op2 = pop(stack);
            if(op1==INT_MIN || op2==INT_MIN) return INT_MIN;
            push(operation(op1,op2,prefix[i]), stack);
        } else {
            printf("Invalid character %c\n", prefix[i]);
            return INT_MIN;
        }
    }
    int ans = pop(stack);
    if(!isEmpty()){
        return INT_MIN;
    }
    return ans;
}





int main(){
    char prefix[MAX];
    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    
    

    int result = prefixChecker(prefix );
    if (result == INT_MIN) {
        printf("Invalid Expression!\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;

}