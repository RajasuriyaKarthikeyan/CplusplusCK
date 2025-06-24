#include <bits/stdc++.h>
#include <string>

using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *current=NULL;

void printList(){
    struct node *p=head;
    while(p!=NULL){
        cout << p->data << " --> ";
        p=p->next;
    }
    cout << "NULL" << endl;
}

void insert(int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    } else {
        struct node *p= head;
        while(p->next != NULL){
            p=p->next;
        }
        p->next = temp;
    }
}

void insertbegin(int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data=data;

    if(head == NULL){
        temp->next = NULL; 
    } else {
        temp->next = head;
    }
    head = temp;
}

void insertafternode(int data, int datanode){
    struct node *p=head;
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data=data;
    while (p!=NULL){
        if(p->data == datanode){
            temp->next = p->next;
            p->next= temp;
            break;
        }
        p=p->next;
    }
}

void deleteNode(int datanode){
    struct node *p=head;
    if(head->data == datanode){
        head = head->next;
    } else {
        while(p->next != NULL){
            if(p->next->data == datanode){
                p->next=p->next->next;
                break;
            }
            p=p->next;
        }    
    }
}

void reversal(){
    struct node *p1 = head;
    struct node *p2 = NULL;
    struct node *p3;
    while(p1 != NULL){
        p3 = p1->next;
        p1->next = p2;
        p2 = p1;
        p1 = p3;
    }
    head = p2;
}

int main(){
    insert(10);
    printList();
    insert(9);
    printList();
    insertbegin(0);
    printList();
    insert(15);
    printList();
    insert(11);
    printList();
    insertafternode(18,10);
    printList();
    insert(1);
    printList();
    deleteNode(0);
    printList();
    insertbegin(100);
    printList();
    deleteNode(9);
    printList();
    deleteNode(1);
    printList();
    reversal();
    printList();
    return 0;
}