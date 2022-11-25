#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
}; 

struct node *head = NULL;
struct node *tail = NULL;


void addNode(int veri){

    if(head == NULL){

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = veri;
        new -> next = NULL;
        head = tail = new;

    }else{
        
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = veri;
        new -> next = NULL;
        tail -> next = new;
        tail = new;
    }
}


void Headaddnode(int veri){


    if(head == NULL){
       
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = veri;
        new -> next = NULL;
        head = tail = new; 

    }else{
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new -> data = veri;
            new -> next = head;
            head = new;
    }
}

int print(){

    struct node *index = head;
    while(index!=NULL){
        printf("%d - ",index->data);
        index = index -> next;
    }
}


int delete(int veri){
    
    struct node *prev = NULL;
    struct node *index = head;

    // head is empty
    if(head == NULL){
        printf("Linked List is empty!");
    }


    // head
    if(head -> data == veri){
        struct node *t = head;
        head = head -> next;
        free(t); 
        return 0;
        
    }


    // data is in Linked List
    while(index != NULL && index -> data != veri){
        prev = index;
        index = index -> next;

    }


    if(index == NULL){
        printf("Aradiğiniz eleman listede bulunmuyor.\n");
        return 0;
    }
    
    prev -> next = index -> next;


    if(tail -> data == veri)
        tail = prev;

    free(index);  
    
    
    return 0;
}
int main(){

    addNode(10);
    addNode(12);
    delete(10);    
    print();

      return 1;
}