#include <iostream>

using namespace std;

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isFull(){
    if(top==MAXSIZE-1){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    } else {
        return 0;
    }
}

void printStack(){
    cout << "Stack Elements : " << endl;
    for(int i=0;i<MAXSIZE;i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}

int pop(){
    int element;
    if(isEmpty() == 1){
        cout << "Stack Empty " << endl;
    } else {
        element = stack[top];
        stack[top] = 0;
        top = top-1;
    }
    return element;
}

void push(int data){
    if(isFull() == 1){
        cout << "Stack is Full, No more Insertion" << endl;
    } else {
        top+=1;
        stack[top] = data;
    }
}

int peek(){
    int element = -1;
    if(isEmpty() == 1){
        cout << "No Peek element : Stack Empty" << endl;
    } else {
        element = stack[top];
    }
    return element;
}

int main(){
    int element;
    cout << "Stack Full/Empty Status : 0 -> False | 1 -> True" << endl;
    element = isFull();
    cout << "Stack Full Status : " << element << endl;
    element = isEmpty();
    cout << "Stack Empty Status : " << element << endl;
    printStack();
    push(10);
    push(20);
    push(30);
    push(40);
    printStack();
    element = pop();
    cout << "Popped Element : " << element << endl;
    element = peek();
    cout << "Peek Element : " << element << endl;
    push(50);
    element = isFull();
    cout << "Stack Full Status : " << element << endl;
    element = isEmpty();
    cout << "Stack Empty Status : " << element << endl;
    printStack();
    push(70);
    push(90);
    push(50);
    push(80);
    printStack();
    element = isFull();
    cout << "Stack Full Status : " << element << endl;
    element = isEmpty();
    cout << "Stack Empty Status : " << element << endl;
    return 0;
}
