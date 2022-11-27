#include <stdio.h>
#include <stdlib.h>


struct node{

    int data;
    struct node *next;
    struct node *prev;

};


struct node *head = NULL;
struct node *tail = NULL;

void addNode(int veri){

    if(head == NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = veri;
        new -> next = NULL;
        new -> prev = NULL;
        head = tail = new;
    }else{
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = veri;
        new -> next = NULL;
        new -> prev = tail;
        tail -> next = new;
        tail = new;
    }
}


void addNodeHead(int veri){

    if(head == NULL){

        struct node *new  = (struct node * )malloc(sizeof(struct node));
        new -> data =veri;
        new -> next = NULL;
        new -> prev = NULL;
        head = tail = new;
        
    }else{

        struct node *new  = (struct node *)malloc(sizeof(struct node));
        new -> data =veri;
        new -> next = head;
        new -> prev = NULL;
        head = new;
    }
}

int delete(int veri){

    struct node *prev = NULL;
    struct node *index = head;

    if(head == NULL){
        printf("The list is empty");
    }

    if(head -> data == veri){

        struct node *t = head;
        head = head -> next;
        free(t);
        return 0;
    }

    while(index -> next != NULL && index -> data != veri){
        prev = index;
        index = index -> next;
    }

    if(index == NULL){
        printf("Aradiginiz node bulunamadi");
    }

    prev -> next = index -> next; 

    free(index);

    return 0;
}

void print(){
    struct node *index = head;
    while(index != NULL){
        printf("%d - ", index -> data);
        index = index->next;
    }
}

void main(){
    addNode(9);
    addNode(8);
    addNode(7);
    addNode(6);
    addNode(5);
    addNodeHead(1);
    delete(7);
    print();
    // printf("%d", tail -> prev -> data);
}