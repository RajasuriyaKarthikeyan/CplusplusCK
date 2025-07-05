#include <iostream>
#include <vector>


using namespace std;

int dividezero() {
    int x = 7;
    try {
        if (x % 2 != 0) {
            
            // Throwing int
            throw -1;
        }
    }
    
    // Catching int
    catch (int e) {
        cout << "Exception Caught: " << e << endl;
    }
    return 0;
}

void OutofRange(){
    vector<int> v = {1, 2, 3};
    
    try {
        // Accessing out of bound element
        v.at(10);
    }
    catch (out_of_range e) {
        cout << "Caught: " << e.what() << endl;  //what prints the exception
    }
}

void CustomDesign(){
    try {
        int choice;
        cout << "Enter 1 for invalid argument, "
            << "2 for out of range: ";
        cin >> choice;

        if (choice == 1) {
            throw invalid_argument("Invalid argument");
        }
        else if (choice == 2) {
            throw out_of_range("Out of range");
        }
        else {
            throw "Unknown error";
        }

    }
    
    // executed when exception is of type invalid_argument
    catch (invalid_argument e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    // executed when exception is of type out_of_range
    catch (out_of_range e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    // executed when no matching catch is found
    catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
}

int main(){
    (void)dividezero();
    OutofRange();
    CustomDesign();
}