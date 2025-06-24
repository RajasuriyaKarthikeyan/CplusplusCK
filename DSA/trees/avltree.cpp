#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
};

int max(int a,int b){
    return (a>b) ? a : b;
}

int height(struct Node *N){
    if(N == NULL)
        return 0;
    return N->height;
}

struct Node *newNode(int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->leftChild;
    struct Node *T2 = x->rightChild;
    x->rightChild = y;
    y->leftChild = T2;
    y->height = max(height(y->leftChild),height(y->rightChild))+1;
    x->height = max(height(x->leftChild),height(x->rightChild))+1;
    return x;
}

struct Node *leftRotate(struct Node *x){
    struct Node *y = x->rightChild;
    struct Node *T2 = y->leftChild;
    y->leftChild = x;
    x->rightChild = T2;
    y->height = max(height(y->leftChild),height(y->rightChild))+1;
    x->height = max(height(x->leftChild),height(x->rightChild))+1;
    return y;
}

int getBalance(struct Node *N){
    if(N == NULL)
        return 0;
    return height(N->leftChild)-height(N->rightChild);
}

struct Node *insertNode(struct Node *node, int data){
    if(node == NULL)
        return newNode(data);
    if(data < node->data)
        node->leftChild = insertNode(node->leftChild, data);
    else if (data > node->data)
        node->rightChild = insertNode(node->rightChild,data);
    else 
        return node;
    node->height = 1+max(height(node->leftChild),height(node->rightChild));
    int balance = getBalance(node);
    if(balance > 1 && data < node->leftChild->data){
        return rightRotate(node);
    }
    if(balance < -1 && data > node->rightChild->data){
        return leftRotate(node);
    }
    if(balance > 1 && data > node->leftChild->data){
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }
    if(balance < -1 && data < node->rightChild->data){
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }
    return node;
}

struct Node *minValueNode(struct Node *node){
    struct Node *current = node;
    while(current->leftChild != NULL){
        current = current->leftChild;
    }
    return current;
}

void printTree(struct Node *node){
    if(node == NULL)
        return;
    if(node != NULL){
        printTree(node->leftChild);
        cout << node->data << " ";
        printTree(node->rightChild);
    }
}

struct Node *deleteNode(struct Node *node, int data){
    if(node == NULL)
        return node;
    if(data < node->data)
        node->leftChild = deleteNode(node->leftChild,data);
    else if(data > node->data)
        node->rightChild = deleteNode(node->rightChild,data);
    else{
        if(node->leftChild == NULL || node->rightChild== NULL){
            struct Node *temp = node->leftChild ? node->leftChild : node->rightChild;
            if(temp == NULL){
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            struct Node *temp = minValueNode(node->rightChild);
            node->data = temp->data;
            node->rightChild = deleteNode(node->rightChild, temp->data);
        }
    }
    if(node == NULL)
        return node;
    node->height = 1+ max(height(node->leftChild),height(node->rightChild));
    int balance = getBalance(node);
    if(balance > 1 && getBalance(node->leftChild) >= 0)
        return rightRotate(node);
    if(balance > 1 && getBalance(node->leftChild) < 0){
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }
    if(balance < -1 && getBalance(node->rightChild) <=0)
        return leftRotate(node);
    if(balance < -1 && getBalance(node->rightChild) > 0){
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }
    return node;
}

int main(){
    struct Node *root = NULL;
    root = insertNode(root, 22);
    root = insertNode(root, 14);
    root = insertNode(root, 72);
    root = insertNode(root, 44);
    root = insertNode(root, 25);
    root = insertNode(root, 63);
    root = insertNode(root, 98);
    cout << "AVL Tree : ";
    printTree(root);
    root = deleteNode(root, 25);
    cout << "\n After deleteion 25" << endl;
    cout << "AVL Tree : ";
    printTree(root);
    return 0;
}
