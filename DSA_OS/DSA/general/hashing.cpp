#include <unordered_map>
#include <iostream>

using namespace std;

#define SIZE 20

struct DataItem
{
    int data;
};

struct DataItem *hashMap[SIZE];

int hashcode(int data){
    return data % SIZE;
}

// DataItem* search(int data){
//     int hashIndex = hashcode(data);

//     while(hashMap[hashIndex] != nullptr){
//         if(hashMap[hashIndex]->data == data)
//             return hashMap[hashIndex];
        
//         hashIndex++;
//         hashIndex%=SIZE;
//     }
//     return nullptr;
// }

void Insert(int data){
    struct DataItem *newItem = new DataItem;
    newItem->data=data;
    int hashIndex = hashcode(data);
    while(hashMap[hashIndex] != nullptr){
        ++hashIndex;
        hashIndex%=SIZE;
    }
    hashMap[hashIndex] = newItem;
    cout << "Insert Key : " << newItem->data << " at Index : " << hashIndex << endl;
}

void DeleteItem(int data){
    cout << "Deleting " << data << endl;
    int hashIndex = hashcode(data);
    while(hashMap[hashIndex] != nullptr){
        if(hashMap[hashIndex]->data == data){
            delete hashMap[hashIndex];
            hashMap[hashIndex] = nullptr;
            return;
        }
        ++hashIndex;
        hashIndex%=SIZE;
    }
    cout << "Item with data " << data << "not found " << endl;
}

int main(){
    Insert(12);
    Insert(13);
    Insert(11);
    Insert(21);
    Insert(31);
    DeleteItem(11);
    DeleteItem(21);
    DeleteItem(31);
    cout << "Contents of Hash Table : " << endl;
    for(int i=0;i<SIZE;i++){
        if(hashMap[i] != nullptr){
            cout << "Index " << i << " : Data : " << hashMap[i]->data << endl;
        } else {
            cout << "Index " << i << " : Empty" << endl;
        }
    }
    return 0;
}

    
