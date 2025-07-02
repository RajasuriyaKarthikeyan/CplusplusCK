#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void printList(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void reverse() {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;  // Update the global head pointer
}

Node* recurseReverse(Node* node){

    if(node == NULL || node->next == NULL){
        return node;
    }
    
    Node *rest = recurseReverse(node->next);
    node->next->next = node;
    node->next = NULL;

    return rest;
}

void insert(int data) {
    Node *temp = new Node();  // Use new instead of malloc
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

int main() {
    int n, val;
    cout << "Enter nodes count: ";
    cin >> n;
    cout << "Enter Node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }

    cout << "Before Reverse: ";
    printList(head);

    reverse();

    cout << "After Reverse: ";
    printList(head);
    head = recurseReverse(head);
    cout << "Recurse Reverse to original: ";
    printList(head);
    return 0;
}
