#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int veri){                  // node oluşturma
    BTREE *new = (BTREE *)malloc(sizeof(BTREE));
    new -> data = veri;
    new -> right = NULL;
    new -> left = NULL;
    return new;
}

BTREE *insert(BTREE *root, int veri){       // node ekleme
    if(root == NULL){
        root = new_node(root);
    }else{
        if(root -> data > veri){
            root -> left = insert(root -> left, veri);
        }else{
            root -> right = insert(root -> right, veri);
        }
    }
    return root;
}


void preorder(BTREE *root){         // sıralama
    if(root != NULL){
        printf("%3d", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder(BTREE *root){        // sıralama
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root -> data);
    }
}


void inorder(BTREE *root){             // sıralama
    if(root != NULL){
        inorder(root->left);
        printf("%3d", root -> data);
        inorder(root -> right);
    }
}


int size(BTREE *root){              // Ağaçtaki düğüm sayısını bulmak
    if(root == NULL){
        return 0;
    }else{
        return size(root->right) + 1 + size(root->left);
    }
}


int height(BTREE *root){                    // ağacın yüksekliğini bulmak
    if(root == NULL){
        return 0;
    }else{
        int left_height, right_hegiht;
        left_height = height(root -> left);
        right_hegiht = height(root -> right);
        if(right_hegiht > left_height){
            return right_hegiht + 1;
        }else{
            return left_height + 1;
        }
    }
}

void mirror(BTREE *root){               // Nodeların yeirni değiştirmek aynalamak
    if(root == NULL){   
        return;
    }else{
        BTREE *temp;
        mirror(root -> left);
        mirror(root -> right);
        temp = root -> left;                // değiştirme işlemi yapılıyor
        root -> left = root -> right;
        root -> right = temp;
    }
}

BTREE *delete_node(BTREE *root, int veri){          // Düğüm silmek
    BTREE *p, *q;

    if(root == NULL)                            // Ağaç boşsa çalışacak
        return NULL;


    if(root -> data == veri){                   // Aranacak düğüm bulunmuşsa çalışacak olan kısım
        if(root -> left == root -> right){
            free(root);
            return NULL;
        }else{
            if(root -> left == NULL){
                p = root -> right;
                free(root);
                return p;
            }else if( root -> right == NULL){
                p = root -> left;
                free(root);
                return p;
            }else{
                p = q = root -> right;

                while(p -> left != NULL){
                    p = p -> left;
                }
                p -> left = root -> left;
                free(root);
                return q;
            }
        }
    }else if(root -> data < veri)                           // Aranan düğüm bulunmamışsa çalışacak
        root -> right = delete_node(root -> right, veri);
    else
        root -> left = delete_node(root -> left, veri);
    return root;
}

BTREE *searchTree(BTREE *root, int veri){               // İstenilen düğümü bulmak
    if(root != NULL){
        if(root -> data == veri){
            return root;
        }else if(root -> data > veri)
            searchTree(root -> left, veri);
        else
            searchTree(root -> left, veri);
    }else{
        return NULL;
    }
}

int istBST(BTREE *root){            // BST ağacı oluğ olmadığınının konrolü
    if(root == NULL)
        return 1;
    if(root -> left != NULL && maxValue(root->left) > root -> data)
        return 0;
    if(root -> right != NULL && minValue(root->left) <= root -> data)
        return 0;
    if(!istBST(root -> left) || !istBST(root -> right))
        return 0;
    return 1;
    
}

int miValue(BTREE *root){           // En küçük node u bulma
    if( root == NULL)
        return 0;
    while(root -> left != NULL){
        root = root -> left;
    }
    return (root -> data);
}

int maxValue(BTREE *root){          // En büyük node u bulma
    if(root == NULL)
        return 0;
    while(root -> right != NULL)
        root = root -> right;
    return (root -> data);
}

int isSame(BTREE *a, BTREE *b){         // 2 Ağacı karşılaştırma
    if(a == NULL && b == NULL)
        return 1;
    else if(a != NULL && b != NULL)
        return (
            a -> data == b -> data && isSame(a->left,b->left) && isSame(a->right,b->right)
        );             // Doğru ise true döner
    else
        return 0;
}
void main(){
     BTREE *root;
     root = insert(root, 5);
}