#include <iostream>
#include <stdbool.h>
using namespace std;
int MAX_SIZE = 5;
int queue[5];
int front = 0;
int rear = -1;
int itemcount = 0;

bool isFull(){
    return itemcount == MAX_SIZE;
}

bool isEmpty(){
    return itemcount == 0;
}

int dequeue(){
    int element = -1;
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
    } else {
        if(front == MAX_SIZE){
            front=0;
        }
        element = queue[front];
        front+=1;
        itemcount-=1;
    }
    return element;
}

void enqueue(int data){
    if(isFull()){
        cout << "Queue is Full" << endl;
    } else {
        if(rear == MAX_SIZE-1){
            rear = -1;
        }
        rear+=1;
        queue[rear] = data;
        itemcount+=1;
    }
}

int peek(){
    int element = -1;
    if(isEmpty()){
        cout << "Peek : Queue is Empty";
    } else {
        if(front == MAX_SIZE){
            element = queue[0];
        } else {
            element = queue[front];
        }
    }
    cout << endl;
    return element;
}

void printQueue(){
    int i=0, j = front;;
    if(isEmpty()){
        cout << "PrintQueue : Queue is Empty";
    } else {
        cout << "Queue : " ;
            while(i!=itemcount){
            if(j == MAX_SIZE){
                j=0;
            }
            cout << queue[j] << " ";
            j+=1;
            i+=1;
        }  
    }
    cout << endl;
}

int main(){
    int element;
    bool QueueStatus;
    QueueStatus = isFull();
    cout << "Queue Full Status : " << QueueStatus << endl;
    QueueStatus = isEmpty();
    cout << "Queue Empty Status : " << QueueStatus << endl;
    printQueue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue();
    element = dequeue();
    cout << "Popped Element : " << element << endl;
    element = peek();
    cout << "Peek Element : " << element << endl;
    enqueue(50);
    QueueStatus = isFull();
    cout << "Queue Full Status : " << QueueStatus << endl;
    QueueStatus = isEmpty();
    cout << "Queue Empty Status : " << QueueStatus << endl;
    printQueue();
    enqueue(70);
    enqueue(90);
    printQueue();
    QueueStatus = isFull();
    cout << "Queue Full Status : " << QueueStatus << endl;
    QueueStatus = isEmpty();
    cout << "Queue Empty Status : " << QueueStatus << endl;
    enqueue(100);
    return 0;
}


