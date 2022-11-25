#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct{
    int front;
    int rear;
    int cnt;
    int data[QUEUE_SIZE];
}queue;


void initialize(queue *q){
    q -> front = 0;
    q -> rear = -1;  //Önce arttıralacağı ve sonra ekleme yapılacağı için -1
    q -> cnt = 0;
}


int isEmpty(queue *q){
    return (q -> cnt == 0);
}

int isFull(queue *q){
    return (q -> cnt == QUEUE_SIZE);
}

void enqueue (queue *q, int x){
    if(!isFull(q)){
        q -> rear++;
        q -> cnt++;

        if(q -> rear == QUEUE_SIZE)
            q -> rear = 0;  //Eğer dizi boş değil fakat rear sonda ise dizinin başındaki boş yerler kullanılır
        q -> data[q -> rear] = x;
    }
}

int dequeue(queue *q){
    if(!isEmpty(q)){
        int x = q -> data[q -> front];// front değişkenini tutuyor
        q -> front++;
        q -> cnt--;
        if(q -> front == QUEUE_SIZE)
            //Front dizinin sonunu gösteriyor olabilir taşma sorunu olmaması için kontrol edilir
            q -> front = 0;
        return x;
    }
}


void main(){
    queue n;
    int x;
    initialize(&n);
    enqueue(&n,1);
    enqueue(&n,2);
    enqueue(&n,3);
    enqueue(&n,4);
    x = dequeue(&n);
    printf("\nSilinen eleman: %d", x);
    x = dequeue(&n);
    printf("\nSilinen eleman: %d", x);
    x = dequeue(&n);
    printf("\nSilinen eleman: %d", x);
    x = dequeue(&n);
    printf("\nSilinen eleman: %d", x);

}