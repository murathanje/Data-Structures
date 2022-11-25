#include <stdio.h>
#include <stdlib.h>


#define STACT_SIZE 4

typedef struct {
    int data[STACT_SIZE];
    int top;  
}stack;


void push(stack *stk, int c){
    if(stk -> top == STACT_SIZE - 1){
        printf("\nStack dolu\n\n");
    }else{
        stk -> top++;
        stk -> data[stk -> top] = c;
    }
}

void reset(stack *stk){
    stk -> top = -1;
}


int pop(stack *stk){
    
    if(stk -> top == -1){
        printf("Stack bos.\n");
    }else{
        int x = stk -> top--;
        return x;
    }
}


void print(stack *stk){
    for (int i = 0; i < STACT_SIZE; i++){
        printf("\n%d", stk -> data[i]);
    }
    
}

int main(){
    int x;
    stack n;
    push(&n ,10);
    push(&n ,11);
    push(&n ,12);
    push(&n ,13);
    print(&n);
    return 0;
}