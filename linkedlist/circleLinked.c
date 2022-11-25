#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
int cnt = 0;

void addNodeHead(int veri)
{

    if (head == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = NULL;
        new->prev = NULL;
        head = tail = new;
        cnt++;
    }
    else
    {

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = head;
        new->prev = tail;
        tail->next = new;
        head = new;
        cnt++;
    }
}
void addNodeEnd(int veri)
{

    if (head == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = NULL;
        new->prev = NULL;
        head = tail = new;
        cnt++;
    }
    else
    {

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = head;
        new->prev = tail;
        tail->next = new;
        tail = new;
        cnt++;
    }
}

int delete (int veri)
{

    struct node *index = head;
    struct node *prev = NULL;

    if (head == NULL)
    {
        printf("The list is empty");
    }

    if (head->data == veri)
    {
        struct node *t = head;
        head = head->next;
        free(t);
        cnt--;
        return 0;
    }

    while (index->next != head && index->data != veri)
    {
        prev = index;
        index = index->next;
    }

    if (index == NULL)
    {
        printf("Aradiginiz node bulunamadi");
    }

    prev->next = index->next;

    free(index);

    cnt--;

    return 0;
}

int print()
{

    struct node *temp = head;
    int i = 0;

    while (i != cnt)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
        i++;
    }
    return 0;
}

int main()
{
    addNodeHead(2);
    addNodeEnd(1);
    addNodeHead(4);
    addNodeEnd(5);
    addNodeHead(3);
    // delete(4);
    printf("\nHead is : %d", head->data);
    printf("\nTail is : %d\n\n", tail->data);
    print();
}
