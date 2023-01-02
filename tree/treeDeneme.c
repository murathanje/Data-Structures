#include <stdio.h>
#include <stdlib.h>

int a = 1;
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

int a = 1;
int find(BTREE *root){
    if((root != NULL) && (root->left != NULL || root->right != NULL)){
        find(root -> left);
        find(root->right);
        return a++;
    }
    return 0;
}

int height(BTREE *root){
    if(root == NULL){
        return -1;
    }else{
        int left_height, right_height;
        left_height = height(root -> left);
        right_height = height(root -> right);
        if(right_height > left_height){
            return right_height + 1;
        }else{
            return left_height + 1;
        }
    }
}


BTREE *delete_node(BTREE *root, int x){
        BTREE *p, *q;

        if(root == NULL)
            return NULL;

        if(root -> data == x){                          // Aranan düğüm bulunduysa çalışacak kısım
            if(root -> left == root -> right){
                free(root);
                return NULL;
            }else{
                if(root -> left == NULL){
                    p = root -> right;
                    free(root);
                    return p;
                }else if(root -> right == NULL){
                    p = root -> left;
                    free(root);
                    return p;
                }else{
                    p = q = root -> right;

                    while (p -> left != NULL)
                        p = p -> left;
                    p -> left = root -> left;
                    free(root);
                    return q;
                }
            }
        }else if(root -> data < x){                        // Aranan düğüm bulunmadıysa çalışacak
            root -> right = delete_node(root -> right , x);
        }else{
            root -> left = delete_node(root -> left, x);
        }
        return root;
}

void postorder(BTREE *root){
    if(root == NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%3d", root -> data);
    }
}

int size(BTREE *root){
    if(root == NULL ){
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
    int x = inorder(root);
    printf("\nInorder is: %d", x);
}