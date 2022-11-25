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

void addHeadNode(int veri)
{

    if (head == NULL)
    {

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = NULL;
        new->prev = NULL;
        head = tail = new;
    }
    else
    {

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = head;
        new->prev = NULL;
        head = new;
    }
}

void addNode(int veri)
{

    if (head == NULL)
    {

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->next = NULL;
        new->prev = NULL;
        head = tail = new;
    }
    else
    {

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = veri;
        new->prev = tail;
        new->next = NULL;
        tail->next = new;
        tail = new;
    }
}

int delete (int veri)
{
    struct node *prev = NULL;
    struct node *index = head;

    if (head == NULL)
    {
        printf("The List is empty\n");
        return 0;
    }

    if (head->data == veri)
    {

        struct node *t = head;
        head = head->next;
        free(t);
        return 0;
    }

    while (index != NULL && index->data != veri)
    {
        prev = index;
        index = index->next;
    }

    if (index == NULL)
    {
        printf("Aradiginiz node bulunamadi.\n");
    }

    prev->next = index->next;

    free(index);

    return 0;
}

void print()
{

    struct node *index = head;

    while (index != NULL)
    {
        printf("%d - ", index->data);
        index = index->next;
    }
}

int main()
{
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);
    addNode(9);
    addHeadNode(4);
    delete(4);
    print();
    // printf("%d", head->next->data);
}
