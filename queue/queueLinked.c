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
void addToQueue(queue *q, int veri){
    int x = 0;
    for(int i = 1; i <= veri; i++){
        if(veri % i  == 0){
            enqueue(q,i);
        }else if(x == 1){
            enqueue(q,i);
        }else if(x == veri){
            enqueue(q,i);
        }
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
        struct node *temp = q -> front;
        while(temp != NULL){
            printf("\n%d", temp ->data);
            temp = temp ->next;
        }

    }
}


void main(){
    int x;
    queue *q;
    initialize(q);
    addToQueue(q,12);
    x = dequeque(q);
    printf("\nDeleted is: %d", x);
    goster(q);
}