#include <iostream>

using namespace std;

struct Heap{
    int* array;
    int size;
    int capacity;
};

Heap* createHeap(int capacity){
    Heap* heap = new Heap;
    heap->array = new int[capacity];
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(Heap* heap, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if(right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    if(largest != i){
        swap(heap->array[i],heap->array[largest]);
        heapify(heap, largest);
    }
}

void insert(Heap* heap, int data){
    if(heap->size == heap->capacity){
        cout << "Heap is Full. No insertion is possible";
        return;
    }
    int i = heap->size++;
    heap->array[i] = data;
    while(i != 0 && heap->array[(i-1)/2]< heap->array[i]){
        swap(heap->array[i], heap->array[(i-1)/2]);
        i= (i-1)/2;
    }
}

void printHeap(Heap* heap){
    cout << "Heap Elements : ";
    for(int i=0;i<heap->size;i++){
        cout << heap->array[i] << " ";
    }
    cout << endl;
}

int deleteMax(Heap* heap){
    if(heap->size == 0){
        cout << "Heap is Empty.No deletion Possible";
        return -1;
    }
    int max = heap->array[0];//store root elememt
    heap->array[0] = heap->array[heap->size - 1]; // replace root with the last element and heapify()
    heap->size--;
    heapify(heap,0);
    return max;
}

void destroyHeap(Heap* heap){
    free(heap->array);
    free(heap);
}

int main(){
    Heap* heap = createHeap(10);
    insert(heap, 33);
    insert(heap, 23);
    insert(heap, 45);
    insert(heap, 43);
    insert(heap, 21);
    insert(heap, 44);
    insert(heap, 30);
    insert(heap, 39);
    insert(heap, 17);
    printHeap(heap);
    int max = deleteMax(heap);
    cout << "Deleted Max element : " << max << endl;
    cout << "After Deletion -> " ;
    printHeap(heap);
    destroyHeap(heap);
    return 0;
}