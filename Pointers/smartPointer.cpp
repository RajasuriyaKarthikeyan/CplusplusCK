#include <iostream>
#include <memory>

using namespace std;

int main(){
    unique_ptr<int> ptr = make_unique<int>(10);
    unique_ptr<int> ptr1 = move(ptr);
    if(!ptr){
        cout << "ptr is null now" << endl;
    } else{
        cout << "move(ptr) is failed" << endl;
    }

    shared_ptr<int> shr = make_shared<int>(1000);
    shared_ptr<int> sh1 = shr;
    shared_ptr<int> sh2 = shr;


    cout << "Shared count : " << sh1.use_count() << endl;
    cout << "shr : " << *shr << " sh1 : " << *sh1 << " sh2 : " << *sh2 << endl;
    
    std::shared_ptr<int> sp = std::make_shared<int>(100);
    std::weak_ptr<int> wp = sp;

    if (auto spt = wp.lock()) { // Check if still exists
        std::cout << "Value: " << *spt << std::endl;
    }

}