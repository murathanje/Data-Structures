#include<stdio.h>
#include<stdlib.h>

//Example struct
struct node{
    int data;
    struct node *next;
};

//Head node for Stack
struct node *top = NULL;

int push(int veri){
    
    //Stack is empty
    if(top == NULL){

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new ->data = veri;
        new ->next = NULL;
        top = new;


    }else{ //Struct is not empty

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = veri;
        new -> next = top;
        top = new;

    }

    return 1;


}

int pop(){

    //Struct is empty
    if(top == NULL){

        printf("Struct is empty!");
        return -100;

    }else{

        struct node *temp = top;
        top = top -> next;
        free(temp);
        return 1;
    }
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();

    int i = 0;
    struct node *index = top;
    while(index != NULL){
        printf("\nStruct %d.elemani : %d", i, index->data);
        index = index -> next;
        i++;

    }
    
    return 1;


}