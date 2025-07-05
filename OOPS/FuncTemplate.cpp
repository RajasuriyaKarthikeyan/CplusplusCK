#include <iostream>

using namespace std;

template<typename Suriya>

Suriya add(Suriya a,Suriya b){
    return a+b;
}

int main(){
    cout << "add<int>(10,20) = " << add<int>(10,20) << endl;
    cout << "add<float>(10.3,20.2) = " << add<float>(10.3,20.2) << endl;
    cout << "add<string>(Rajasuriya,Karthikeyan) = " << add<string>("Rajasuriya"," karthikeyan") << endl;
}