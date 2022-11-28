#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node BTREE;

BTREE *new_node(int veri){
    BTREE *new = (BTREE *)malloc(sizeof(BTREE));
    new -> data = veri;
    new -> left = new -> right = NULL;
    return new;
}


BTREE *insert(BTREE *root, int veri){
    if(root == NULL){
        root = new_node(veri);
    }else{
        if(veri < root -> data){
            root -> left = insert(root -> left, veri);
        }else{
            root -> right = insert(root -> right, veri);
        }
    }
    return root;
}

void preorder(BTREE *root){
    if(root != NULL){
        printf("%3d", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(BTREE *root){
    if(root == NULL){
        inorder(root -> left);
        printf("%3d", root -> data);
        inorder(root -> right);
    }
}

void postorder(BTREE *root){
    if(root == NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%3d", root -> data);
    }
}

int size(BTREE *root){
    if(root == NULL){
        return 0;
    }else{
        return (size(root ->left) + 1 + size(root-> right));
    }
}



void main(){
    BTREE *root = NULL;
    int i = 0;

    do{
        printf("\nLutfen eklenecek sayiyi giriniz.\nSayi ");
        scanf("%d", &i);
        if(i != -1)
            root = insert(root, i);

    }while(i != -1);

    printf("Size is %d", size(root));
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}