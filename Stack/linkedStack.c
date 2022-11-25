#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

struct node{
    struct node *next;
    int data;    
};

typedef struct{
    struct node *top;
    int cnt;
}stack;


int isEmpty(stack *stk){
    if (stk->cnt == 0)
        return 1;
    return 0;
}

int isFull(stack *stk){
    if (stk->cnt == STACK_SIZE)
        return 1;
    return 0;
}

void push(stack *stk, int c){
    if(!isFull(stk)){
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> data = c;
        temp -> next = stk -> top;
        stk -> top = temp;
        stk -> cnt++;
    }else{
        printf("\nStack is full");
    }
}


int pop(stack *stk){
    if(!isEmpty(stk)){
        struct node *temp = stk -> top;
        stk -> top = stk -> top -> next;    
        int x = temp -> data;
        free(temp);
        stk -> cnt--;
        return x;
    }
    return (printf("\nStack is empty"));
}

int top(stack *stk){
    if(!isEmpty(stk)){
        return(printf("\nTop is : %d",stk -> top -> data));
    }
    return printf("\nStack is empty");
}

void initialize(stack *stk){
    stk -> top = NULL;
    stk -> cnt = 0;
}


void main(){
    int x;
    stack s;
    initialize(&s);
    push(&s, 10);
    push(&s, 11);
    push(&s, 12);
    x = pop(&s);
    printf("\nDeleted node is : %d", x);
    x = pop(&s);
    printf("\nDeleted node is : %d", x);
    top(&s);
}