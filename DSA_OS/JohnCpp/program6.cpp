#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str1[] = "Hello";
    char str2[] = "Madrid";
    char str3[] = "";
    cout << "String 1" << str1 << endl;
    cout << "String 2" << str2 << endl;
    strcpy(str3,str2);
    cout << "String 3 after strcpy " << str3 << endl;
    strcat(str1, str2);
    cout << "String 1 after concatenation " << str1 << endl;
    cout << "Length of String 2 " << strlen(str2) << endl;
    char *ret1;
    char *ret2;
    ret1 = strstr(str1,str3);
    cout << "Strstr(str1, str3) " << ret1 << endl;
    ret2 = strchr(str3, 'r');
    cout << "strchr(str3, r) " << ret2 << endl;
    return 0;
}