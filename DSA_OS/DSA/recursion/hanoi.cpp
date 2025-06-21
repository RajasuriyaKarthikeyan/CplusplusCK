#include <iostream>

using namespace std;

void HanoiTower(int n, char source, char dest, char aux){
    if(n==1){
        cout << "Disk " << n << " is moved from " << source << "to " << dest << endl;
    } else {
        HanoiTower(n-1, source, aux, dest);
        cout << "Disk " << n << " is moved from " << source << "to " << dest << endl;
        HanoiTower(n-1,aux, dest, source);
    }
}

int main(){
    cout << "Disk size : 3 " << endl;
    HanoiTower(3, 'A', 'B', 'C');
    return 0;
}