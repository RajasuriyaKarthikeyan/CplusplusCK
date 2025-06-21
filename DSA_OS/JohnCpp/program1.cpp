#include <iostream>
using namespace std;
#define NEW_VARIABLE 9999

int main()
{
    cout << "hello john" << endl;
    cout << "New variable macro" << NEW_VARIABLE << endl;
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}