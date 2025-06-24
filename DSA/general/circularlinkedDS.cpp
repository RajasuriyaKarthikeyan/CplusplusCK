#include <bits/stdc++.h>
#include <string>

using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;

void printList(){
    struct  node *temp=head;
    if(temp->next == head){
        cout << temp->data;
    } else {
        while (temp->next != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
    }
    cout << "->HEAD" <<endl;
}

void insertBegin(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head == NULL || last ==NULL){
        temp->next = temp;
        head = temp;
        last = temp;
    } else {
        temp->next = head;
        last->next = temp;
        head = temp;
    }
}

void insertLast(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head == NULL || last ==NULL){
        temp->next = temp;
        head = temp;
        last = temp;
    } else {
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

void insertAfter(int data, int dataNode){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(dataNode == last->data){
        insertLast(data);
    } else {
        struct node *p1=head;
        while(p1 != last){
            if(p1->data == dataNode){
                temp->next= p1->next;
                p1->next = temp;
                break;
            }
            p1=p1->next;
        }
    }
}

void deleteHead(){
    struct node *temp = head;
    if(head->next == head){
        head = NULL;
        last = NULL;
    } else {    
        last->next = head->next;
        head = head->next;
    }
    free(temp);
}

void deleteLast(){
    if(last->next == last){
        head = NULL;
        last = NULL;
    } else {
        struct node *temp = head;
        while(temp->next != last){
            temp= temp->next;
        }
        temp->next = head;
        last = temp;
    }
}

void deleteNode(int dataNode){
    if(head->data == dataNode){
        deleteHead();
    } else if (last->data == dataNode){
        deleteLast();
    } else {
        struct node *temp = head;
        while(temp->next!=last){
            if(temp->next->data == dataNode){
                temp->next = temp->next->next;
                break;
            }
            temp=temp->next;
        }
    }
}

int main(){
    insertBegin(10);
    insertBegin(20);
    printList();
    insertLast(30);
    insertLast(40);
    printList();
    insertAfter(50,10);
    insertAfter(60,40);
    printList();
    deleteHead();
    printList();
    deleteLast();
    printList();
    deleteNode(30);
    printList();
    return 0;
}