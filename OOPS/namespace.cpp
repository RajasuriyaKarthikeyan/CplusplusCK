#include <iostream>

using namespace std;

namespace Suriya{
    int Number = 8;
    void PrintNumber(){
        cout << "Namespace Suriya Number : " << Number <<endl;
    }
}

namespace Raja{
    int Number = 17;
    void PrintNumber(){
        cout << "Namespace Raja Number : " << Number << endl;
    }
}

namespace Raja::CK{
    int Number = 10;
    void PrintNumber(){
        cout << "Namespace CK Number : " << Number << endl;
    }
}

int main(){
    Suriya::PrintNumber();
    Raja::PrintNumber();
    Raja::CK::PrintNumber();
}