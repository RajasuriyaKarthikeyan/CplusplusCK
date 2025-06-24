#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Node *root=NULL;

void Insert(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *current, *parent;
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;

    if(root==NULL){
        root = temp;
    } else {
        current = root;
        while(1){
            parent = current;
            if(parent->data < data){
                current = current->rightChild;
                if(current == NULL){
                parent->rightChild = temp;
                return;
            }
            } else {
                current =current->leftChild;
                if(current == NULL){
                parent->leftChild = temp;
                return;
            }
            }

            
        }
    }
}

struct Node* Search(int data){
    struct Node *current = root;
    while(current->data != data){
        if(current->data > data){
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }

        if(current == NULL){
            return NULL;
        }
    }
    return current;
}

void InorderTraversal(struct Node* temp){
    if(temp != NULL){
        InorderTraversal(temp->leftChild);
        cout << temp->data << " ";
        InorderTraversal(temp->rightChild);
    }
}

void PreorderTraversal(struct Node* temp){
    if(temp != NULL){
        cout << temp->data << " ";
        PreorderTraversal(temp->leftChild);
        PreorderTraversal(temp->rightChild);
    }
}

void PostorderTraversal(struct Node* temp){
    if(temp != NULL){
        PostorderTraversal(temp->leftChild);
        PostorderTraversal(temp->rightChild);
        cout << temp->data << " ";
    }
}

int main(){
    int arr[7] = { 31, 25, 38, 33, 40, 22, 28};
    for(int i=0;i<7;i++){
        Insert(arr[i]);
    }
    cout << "\nInorder Traversal : ";
    InorderTraversal(root);
    cout << "\nPre-Order Traversal : ";
    PreorderTraversal(root);
    cout << "\nPost-Order Traversal : ";
    PostorderTraversal(root);
    struct Node *searchNode = Search(33);
    if(searchNode!=NULL){
        cout << "\nData Found <->" << searchNode->data;
    } else {
        cout << "\nData Not Found";
    }
    searchNode = Search(21);
    if(searchNode!=NULL){
        cout << "\nData Found <->" << searchNode->data << endl;
    } else {
        cout << "\nData Not Found" << endl;
    }
    return 0;
}