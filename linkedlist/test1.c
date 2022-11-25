#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *addNode(int veri, struct node *head){

    if(head == NULL){

        head = (struct node *)malloc(sizeof(struct node));
        head -> data = veri;
        head -> next = NULL;

    }else{

        

    }
};


void main(){
    struct node *head;
    struct node *temp;
    *addNode(12, head);
};