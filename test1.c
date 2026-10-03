#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char infix[100];
char postfix[100];
char next;

typedef struct Stack{
    int top;
    char data[MAX];
}Stack;


void createStack(Stack* S){
    S->top=-1;
}

int isFull(Stack* S){
    return (S->top==MAX);
}

int isEmpty(Stack* S){
    return (S->top==-1);
}

void push(Stack* S,char value){
    if(isFull(S))
      printf("Stack Overflow\n");
    else{
        S->data[++(S->top)]=value;
    }
   
}

char topele(Stack *S){
    if(isEmpty(S))
        printf("No element in stack\n");
    else
        return (S->data[S->top]);
}

char pop(Stack *S){
    if(isEmpty(S)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        char ch=topele(S);
        S->top--;
        return ch;

        
    }
}


int main(){
    Stack S;
    createStack(&S);
    push(&S,'A');
    push(&S,'B');
    push(&S,'*');
    push(&S,'+');
    while(!isEmpty(&S)){
        printf("%c ",pop(&S));
    }
}