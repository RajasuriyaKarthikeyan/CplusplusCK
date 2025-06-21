#include <stdio.h>

void function_1(){
    printf("Function_1() \n");
}

void function_2(){
    printf("Function_2() \n");
}

void function_3(int a){
    printf("Function_3() a=%d \n", a);
}

void function_4(int b){
    printf("Function_4() b=%d \n", b);
}

typedef void (*func_ptrarg)(int);

int main(){
    void (*func_ptr)();

    func_ptr = function_1;
    func_ptr();

    func_ptr = &function_2;
    func_ptr();

    void (*func_ptrInt)(int);

    func_ptrInt = function_3;
    func_ptrInt(10);

    func_ptrInt = &function_4;
    func_ptrInt(100);

    func_ptrarg f1;
    f1 = function_3;
    f1(25);

/*Function_1() 
Function_2() 
Function_3() a=10 
Function_4() b=100 
Function_3() a=25 */
    return 0;
}