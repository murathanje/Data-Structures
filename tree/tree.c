#include <stdlib.h>
#include <stdio.h>


struct node{
    struct node *left;
    struct node *right;
    char[10] ad;
    char[10] soyad;
    int number;
    int vize;
    int final;
    int data
};


struct node *new_node(int vize,int final,int number,char[] ad, char[] soyad){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new -> vize = vize;
    new -> final = vize;
    new -> number = vize;
    new -> ad   = ad;
    new -> soyad = soyad;
    new -> left = NULL;
    new -> right = NULL;

    return new;
}


struct node *insert(struct node *root, int veri){
    if(root != NULL){
        if(veri < root -> data)
            root -> left = insert(root -> left, veri);
        else
            root -> right = insert(root -> right, veri);
    }else{
        root = new_node(veri);
    }
    return root;
}


void preorder(struct node *root){
    if(root != NULL){
        printf("%3d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);

    }
}
void inorder(struct node *root){
    if(root != NULL && (root->left != NULL || root->right != NULL)){
        inorder(root->left);
        printf("%3d ", root -> data);
        inorder(root->right);
    }
}
void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%3d ", root -> data);
    }
}

int size(struct node *root){
    if(root == NULL){
        return 0;
    }else{
        return (size(root -> left) + 1 + size(root -> right));
    }
}

int x = 0;

// void ortalama(BTREE *root){
//     if(root!=NULL){
//         inorder(root -> left);
//         x += (root -> vize * 0,4)+(root-> final*0,6);
//         inorder(root -> right);
//     }
// }

// int ortalama = x / size(root);

// void ortamaUstu(BTREE root){
//     if(root!=NULL){
//         inorder(root -> left);
//         if(root -> data > x){
//             printf("\nAdı: %s\nSoyadı: %s\nNumara: %d\nVize: %d\nFinal: %d",root->ad, root->soyad, root -> number, root->vize, root->final);
//         }
//         inorder(root -> right);
//     }
// }

int main(){
    struct node *myRoot = NULL;
    int i = 0;

    do{
        printf("\nAgaca veri eklemek icin sayi giriniz...\nSayi: ");
        scanf("%d", &i);
        if(i != -1)
            myRoot = insert(myRoot, i);
    }while(i != -1);
   
    preorder(myRoot);
    printf("\n");
    inorder(myRoot);
    printf("\n");
    postorder(myRoot);
    printf("\n");
    int x = size(myRoot);
    printf("\n Agac sayisi: %d", x);
    return 0;
    
}