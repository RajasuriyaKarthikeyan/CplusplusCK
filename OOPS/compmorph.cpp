#include <iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    void show(double d) {
        cout << "Double: " << d << endl;
    }
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print obj;
    obj.show(10);
    obj.show(3.14);
    obj.show("Hello");
    return 0;
}
