#include<stdio.h>
#include<string.h>
#include<ctype.h>


#define MAX 30
char stack[MAX];
int top = -1;

void push(char data){
    if(top == MAX-1){
        printf("overFlow");
        return;
    }
    stack[++top] = data;
}

char pop(){
    if(top == -1){
        printf("underFlow");
        return '\0';
    }
    return stack[top--];
}

char peek(){
    if(top == -1){
        printf("underFlow");
        return '\0';
    }
    return stack[top];
}

int isEmpty(){
    return top == -1;
}

int priority(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '^' ){
        return 3;
    }
    return -1;
}

void reverse(char arr[]){
    int i = 0;
    int j = strlen(arr) -1;
    while (i< j)
    {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
}

void infixToPostfix(char infix[] , char postfix[]){
    char *e = infix;
    int k = 0 ;
    while (*e != '\0')
    {
        if(isalnum(*e)){
            postfix[k++] = *e;
        }
        else if(*e == '(' || *e == '{' || *e == '['){
            push(*e);
        }
        else if(*e == ')' ){
            while (peek() != *e)
            {
                postfix[k++] = pop();
            }
            if(!isEmpty()) pop();
        }
        else if(*e == '}' ){
            while (peek() != *e)
            {
                postfix[k++] = pop();
            }
            if(!isEmpty()) pop();
            
        }
        else if(*e == ']' ){
            while (peek() != *e)
            {
                postfix[k++] = pop();
            }
            if(!isEmpty()) pop();
            
        }
        else{
            while (priority(*e) <= priority(peek()) )
            {
                postfix[k++] = pop();
            }
            push(*e);
            
        }
        e++;


    }
    while (!isEmpty())
    {
        postfix[k++] = pop();
    }
    
    postfix[k] = '\0';
    
}

void infixToPerfix(char infix[] , char perfix[]){
    char tempinfix[MAX];
    strcpy(tempinfix , infix);
    reverse(tempinfix);
   for(int i = 0 ; i<strlen(tempinfix) ; i++){
    if(tempinfix[i] == '('){

        tempinfix[i] = ')';
    }
    if(tempinfix[i] == '{'){

        tempinfix[i] = '}';
    }
    if(tempinfix[i] == '['){

        tempinfix[i] = ']';
    }
    if(tempinfix[i] == ')'){

        tempinfix[i] = '(';
    }
    if(tempinfix[i] == '}'){

        tempinfix[i] = '{';
    }
    if(tempinfix[i] == ']'){

        tempinfix[i] = '[';
    }
   }
   char postfix[MAX];

   infixToPostfix(tempinfix , postfix);
   reverse(postfix);
   strcpy(perfix, postfix);
    
}
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPerfix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}


