#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *head=NULL;
struct node *last=NULL;

void printfromHead(){
    struct node *temp=head;
    cout << "Printing from Head : NULL->";
    while(temp!=NULL){
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printfromLast(){
    struct node *temp=last;
    cout << "Printing from Last : NULL->";
    while(temp!=NULL){
        cout << temp->data << "<->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void inserthead(int data){
    cout << "Inserting at head : " << data << endl;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head==NULL){
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        last = temp;
    } else{
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
}

void insertLast(int data){
    cout << "Insering at last : " << data << endl;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(last==NULL){
        temp->next = NULL;
        temp->prev = NULL;
        last = temp;
        head = temp;
    } else{
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp; 
    }
}

void insertafter(int data, int target){
    cout << "Insert " << data << " after : " << target << endl;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    struct node *p=head;
    if(last->data == target){
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;
    } else {
        while(p->next!=NULL){
            if(p->data==target){
                temp->next = p->next;
                temp->prev = p;
                p->next->prev = temp;
                p->next = temp;
                break;
            } else{
                p=p->next;
            }
        }
    }    
}

void deletefirst(){
    cout << "Deleting Head " << endl;
    struct node *temp = head;
    if(head->next == NULL){
        head = NULL;
        last = NULL;
    } else {
        head->next->prev = NULL;
    }
    head= head->next;
    free(temp);
}

void deleteLast(){
    cout << "Deleting Last " << endl;
    struct node *temp = last;
    if(last->prev == NULL){
        head = NULL;
        last = NULL;
    } else {
        temp->prev->next = NULL;
    }
    last = last->prev;
    free(temp);
}

void deletetarget(int target){
    cout << "Deleting element : " << target << endl;
    struct node *temp = head;
    if(target == head->data){
        cout << "Target Element is head node -> ";
        deletefirst();
    } else if(target == last->data){
        cout << "Target Element is last node -> ";
        deleteLast();
    } else{
        while(temp->next != NULL){
            if(temp->data == target){
                temp->prev->next=temp->next;
                temp->next->prev = temp->prev;
                break;
            }
            temp=temp->next;
        }
        free(temp);
    }
}

int main(){
    insertLast(10);
    printfromHead();
    printfromLast();
    inserthead(1);
    insertLast(11);
    printfromHead();
    printfromLast();
    insertafter(100,10);
    printfromHead();
    printfromLast();
    insertafter(111,1);
    printfromHead();
    printfromLast();
    insertafter(110,11);
    printfromHead();
    printfromLast();
    deletefirst();
    printfromHead();
    printfromLast();
    deleteLast();
    printfromHead();
    printfromLast();
    deletetarget(10);
    printfromHead();
    printfromLast();
    deletetarget(100);
    printfromHead();
    printfromLast();
    deletetarget(11);
    printfromHead();
    printfromLast();
    return 0;
}