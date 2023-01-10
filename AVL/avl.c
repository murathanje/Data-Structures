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
    AVLTREE *new = (AVLTREE *)malloc(sizeof(AVLTREE));
    new -> data = veri;
    new -> right = NULL;
    new -> left = NULL;
    new -> height = 0;
    return new;
}

int maxHeight(int x, int y) {
    if(x >= y)
        return x;
    return y;
}


int height(AVLTREE *tree){
    if(tree == NULL){
        return -1;
    }else{
        int left_height, right_height;
        left_height = height(tree -> left);
        right_height = height(tree -> right);

        if(right_height > left_height){
            return right_height + 1;
        }else{
            return left_height + 1;
        }
    }
}

// Single Rotation

AVLTREE *rightRotate(AVLTREE *z){   
    AVLTREE *temp = z -> left;         // z düğümünün sol çocuğu tempe atanıyor.
    z -> left = temp -> right;         // tempin sağ çocuğu z'nin sol çocuğu olarak atanıyor.
    temp -> right = z;                 // z düğümü temp'in sağ çocuğu olarak atanıyor.

    // Yükseklikler düzenleniyor.
    z->height = maxHeight(height(z->left), height(z->right)) + 1;
    temp->height = maxHeight(height(temp->left), height(temp->right)) + 1;
    return temp;
    
}

AVLTREE *leftRotate(AVLTREE *z){   
    AVLTREE *temp = z -> right;
    z -> right = temp -> left;
    temp -> left = z;
    z -> height = maxHeight(height(z->left), height(z->right)) + 1;
    temp -> height = maxHeight(height(temp->left), height(temp->right)) + 1;
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




AVLTREE *insertToAVL(AVLTREE *tree, int data){
    if(tree != NULL){

        if(data<tree->data)
		 tree->left=insertToAVL(tree->left,data);
		else
		 tree->right=insertToAVL(tree->right, data);

        tree->height = maxHeight(height(tree->right), height(tree->left)) + 1;

        if(height(tree -> left) - height(tree -> right) > 1 && data < tree -> left -> data){
            return rightRotate(tree);
        } 

        if((height(tree -> left)- height(tree -> right)) > 1 && data > tree -> left -> data){
            return leftRightRotate(tree);
        }

        if((height(tree -> right) - height(tree -> left)) > 1 && data > tree -> right -> data){
            return leftRotate(tree);
        }

        if((height(tree -> right) - height(tree -> left)) > 1 && data < tree -> left -> data){
            return rightLeftRotate(tree);
        }
    }else{
        tree = newNode(data);
    }
    return tree;
}


int getBalance(AVLTREE *origin){
    
    if(origin == NULL)
        return 0;
    return height(origin -> left) - height(origin -> right);

}

AVLTREE *minValue(AVLTREE *tree){
    if(tree != NULL){
        while(tree -> left != NULL){
            tree = tree -> left;
        }
    }
    return tree;
}

AVLTREE *delete(AVLTREE *tree, int data){

    if(tree == NULL){
        return tree;
    }else if(data > tree -> data){                  // Silinecek değer ebeveynin değerinden büyükse
        tree -> left = delete(tree -> left, data);
    }else if(data < tree -> data){                 // Silinecek değer ebeveynin değerinden küçükse
        tree -> right = delete(tree -> right, data);
    }else{                                         // Silinecek değer bulunduysa

        if(tree -> left == NULL || tree -> right == NULL){
            AVLTREE *temp = tree -> left ? tree -> left : tree -> right;

            if(temp == NULL){   // Düğümün hiç çocuğu yoksa
                temp = tree;
                tree = NULL;
            }else{              // Düğümün çocucğu varsa
                *tree = *temp;
            }
            free(temp);
        }else{                 // eğer silinecek düğümün iki çocuğu varsa
            AVLTREE *temp = minValue(tree -> right);

            tree -> data = temp -> data;

            tree -> right = delete(tree -> right, temp -> data);
        }
    }

    if(tree == NULL){
        return tree;
    }

    tree -> height = maxHeight(height(tree -> right), height(tree -> left)) + 1;
    // Eğer balans 1’den büyükse ve sol alt ağacın balansı 0’dan büyük veya eşitse
    if (getBalance(tree) > 1 && getBalance(tree->left) >= 0){
        return rightRotate(tree);
    }

    // Eğer balans 1’den büyükse ve sol alt ağacın balansı 0’dan küçükse
    if (getBalance(tree) > 1 && getBalance(tree->left) < 0){
        return leftRightRotate(tree);
    }

    // Eğer balans -1’den küçükse ve sağ alt ağacın balansı 0’dan küçükse
    if (getBalance(tree) < -1 && getBalance(tree->right) <= 0){
        return leftRotate(tree);
    }

    // Eğer balans -1’den küçükse ve sağ alt ağacın balansı 0’dan büyükse
    if (getBalance(tree) < -1 && getBalance(tree->right) > 0){
        return rightLeftRotate(tree);
    }
    return tree;
}

int inorder(AVLTREE *tree){
    if(tree != NULL){
        inorder(tree -> left);
        printf("\n%3d",tree -> data);
        inorder(tree -> right);
    }
}

void main(){
    AVLTREE *tree = NULL;
    tree = insertToAVL(tree, 1);
    tree = insertToAVL(tree, 2);
    tree = insertToAVL(tree, 3);
    tree = insertToAVL(tree, 4);
    int findHegiht = 0;
    findHegiht =  height(tree);
    printf("\nHeight is : %d\n", findHegiht);
    inorder(tree);
}