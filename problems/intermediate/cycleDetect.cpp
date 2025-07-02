#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

bool DetectCycle(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void printList(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
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
    if(DetectCycle(head)){
        cout << "Cycle Detected" << endl;
    } else {
        cout << "Cycle Not Detected "<< endl;
    }
    return 0;
}
