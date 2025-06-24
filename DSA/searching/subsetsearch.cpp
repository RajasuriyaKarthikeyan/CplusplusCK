#include <bits/stdc++.h>
#include <string>

using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *current=NULL;


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
    temp->next = NULL;

    if(current == NULL){
        current = temp;
    } else {
        struct node *p= current;
        while(p->next != NULL){
            p=p->next;
        }
        p->next = temp;
    }
}

bool subsetSearch(){
    struct node *ptr1 = head, *ptr2=current, *ptr = head;;
    if(head == NULL && current == NULL)
        return true;
    if((head==NULL && current!=NULL) || (head!=NULL && current==NULL))
        return false;
    while (ptr1 != NULL)
    {
        ptr1 = ptr;
        while (ptr2 != NULL)
        {
            if(ptr1->data == ptr2->data){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            } else {
                break;
            }
        }
        if(ptr2 == NULL)
            return true;
        ptr2 = current;
        ptr = ptr->next;
    }
    return false;
}

int main(){
    insert(10);
    insert(9);
    insert(15);
    insert(11);
    insert(12);
    insert(1);
    insertbegin(11);
    insertbegin(12);
    insertbegin(1);
    bool search = subsetSearch();
    cout << "Subset present : " << search << endl;
    return 0;
}