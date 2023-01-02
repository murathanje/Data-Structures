#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *right;
    struct node *left;
    int data;
    int height;
};

typedef struct node AVLTREE;


AVLTREE *newNode(int veri){
    AVLTREE *new = (struct node *)malloc(sizeof(AVLTREE));
    new -> data = veri;
    new -> right = NULL;
    new -> left = NULL;
    new -> height = NULL;
    return new;
}



// Single Rotation

AVLTREE *rightRotate(AVLTREE *z){   
    AVLTREE *temp = z -> left;         // z düğümünün sol çocuğu tempe atanıyor.
    z -> left = temp -> right;         // tempin sağ çocuğu z'nin sol çocuğu olarak atanıyor.
    temp -> right = z;                 // z düğümü temp'in sağ çocuğu olarak atanıyor.

    // Yükseklikler düzenleniyor.
    z -> height = maxValue(height(z->left), height(z->right)) + 1;
    temp -> height = maxValue(height(temp->left), height(temp->right)) + 1;
    return temp;
    
}

AVLTREE *leftRotate(AVLTREE *z){   
    AVLTREE *temp = z -> right;
    z -> right = temp -> left;
    temp -> left = z;
    z -> height = maxValue(height(z->left), height(z->right)) + 1;
    temp -> height = maxValue(height(temp->left), height(temp->right)) + 1;
    return temp;
}


//Double rotation

AVLTREE *leftRightRotate(AVLTREE *z){
    z -> left = leftRotate(z -> left);  // y düğümü sola döndürülüyor
    return rightRotate(z);              // zig-zig sola döndürülüyor
}

AVLTREE *rightLeftRotate(AVLTREE *z){
    z->right = rightLeftRotate(z->right);        // y düğümü sola döndürülüyor
    return leftRotate(z);                        // zig-zig sağa döndürülüyor
}

int maxValue(AVLTREE* root) {
    if(root == NULL)
        return 0;
    while(root -> right != NULL)
        root = root -> right;
    return(root -> data);
}



AVLTREE *insertToAVL(AVLTREE *tree, int x){
    if(tree != NULL){
        if(x < tree -> data){
            tree -> left = insertToAVL(tree -> left, x);
        }else if(x > tree -> data){
            tree -> right = insertToAVL(tree -> right, x);
        }else{
            return tree;
        }

        tree -> height = maxValue(height(tree -> right), height(tree -> left)) + 1;

        if(height(tree -> left) - height(tree -> right) > 1 && x < tree -> left -> data){
            return rightRotate(tree);
        } 
    }
}