#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
struct node {
    int data;
    struct node *next;
};


typedef struct{
    int cnt;
    struct node *front;
    struct node *rear;
}queue;



void initialize(queue *q){
    
    q -> cnt = 0;
    q -> front = q -> rear = NULL;  //NULL değeri her ikisine de atanır.

}

int isEmpty(queue *q){
    return (q -> cnt == 0);
}

int isFull(queue *q){
    return (q -> cnt == QUEUE_SIZE);
}


void enqueue(queue *q, int x){

    if(!isFull(q)){ //Kuyruğun doluluğu kontrol ediliyor
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> next = NULL;
        temp -> data = x;
        if(isEmpty(q)){
            q -> front  = q -> rear = temp;
        }else{
            q -> rear -> next = temp;
            q -> rear = temp;
        }
        q -> cnt++;

}

}

int dequeque(queue *q){
    if(!isEmpty(q)){                            //Kuyruk boş mu diye kontrol edildi
        struct node *temp = q -> front;         
        int x = temp -> data;                   //Silinmeden önceki veri saklanıyor
        q -> front = temp -> next;
        free(temp);
        q -> cnt--;
        return x;
    }
}


void goster(queue *q){
    if(!isEmpty(q)){
        printf("\nThe front is : %d", q -> front ->data);
        printf("\nThe rear is : %d", q -> rear -> data);
        printf("\nThe cnt : %d", q -> cnt);
    }
}


void main(){
    int x;
    queue *q;
    initialize(q);
    enqueue(q,10);
    enqueue(q,11);
    enqueue(q,12);
    enqueue(q,13);
    x = dequeque(q);
    printf("\nDeleted node is: %d", x);
    goster(q);
}