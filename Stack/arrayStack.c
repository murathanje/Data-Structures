#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 3

typedef struct{
 	int data[STACK_SIZE];
	int top;
}stack;

void initialize(stack * stk){
	stk->top=-1;
}

void push( stack * stk,int c){
	if(stk->top!= STACK_SIZE-1){
	 	stk->top++;
		stk->data[stk->top]=c;
		//printf("\n %d Added..",c);
	}
	else
		printf("\nStack is Full!!");
}

int pop (stack * stk){
	if(stk->top!=-1){
		return stk->data[stk->top--];
	}
        return printf("\n Stack is Empty!!");
        
}

void print(stack *stk){
        int i;
        if(stk -> top != -1){

                for(i = 0; i < STACK_SIZE; i++){
                        printf("\n%d\n", stk -> data[i]);
                }
        }
}


int main(){
        int x;
        stack s;
        initialize(&s);
        push(&s,10);
        push(&s,11);
        push(&s,14);
        x = pop(&s);
        printf("%d", x);
        x = pop(&s);
        printf("%d", x);
        x = pop(&s);
        printf("%d", x);
        x = pop(&s);
        printf("%d", x);
        push(&s, 7);
        print(&s);
        return 0;

}
