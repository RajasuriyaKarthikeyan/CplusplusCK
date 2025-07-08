#include <iostream>

using namespace std;

/*Pointer is used to hold the address of another variable1 */


void printSurya(){
    cout << "PrintSurya() called " << endl;
}

void printRaja(int r){
    cout << "printRaja(int r) called " << r << endl;
}

int addValue(int a, int b){
    return a+b;
}

int main(){
    int a= 10;
    int *p = &a; // pointer points to address of a
    cout << " a : " << a << endl; // value in variable
    cout << "*p : " << *p << endl; // Value present in the address pointed
    cout << "&a : " << &a <<endl; // Address of a
    cout << "p : " << p <<endl; // Address of the pointer variable holding
    cout << "&p : " << &p << endl; //Address of pointer variable

    int **pp = &p; // pointer points to address of p which points to a
    cout << "**pp : " << **pp << endl;  // double pointer value
    cout << "*pp :"  << *pp << endl;
    cout << "pp : " << pp << endl; // address of the pointer variable holding
    cout << "&pp : " << &pp << endl; // address of double pointer variabke
    
    int ***ppp = &pp;
    cout << "***ppp : " << ***ppp << endl;
    cout << "**ppp : " << **ppp << endl;
    cout << "*ppp : " << *ppp << endl;
    cout << "ppp : " << ppp << endl;
    cout << "&ppp : " << &ppp << endl;

    int *ptr = nullptr; // Nullptr
    int *point ; // wild pointer - just declare no init

    int *dptr = new int(10);
    delete dptr; // Post deletion, dptr is dangling pointer as its points freed /deleted memory


    void *vptr;
    int n = 10;
    vptr = &n;
    cout << "*vptr : " <<  *(int*)vptr << endl; //required casting

    void (*funcptr)() = printSurya; // points to the function address
    funcptr(); // calls the function 

    void (*intptr)(int) = &printRaja; // points to the function address
    intptr(10); // calls the function
    
    int (*addptr)(int,int) = &addValue;
    cout << addptr(200,300) << endl;

    int arr[] = {10, 20, 30, 40, 50, 60};
    int *arrptr = arr;

    for(int i=0;i< sizeof(arr)/sizeof(int);i++){
        cout << *(arrptr+i) << endl;
    }
    
    int **arrptr2d = (int**)malloc(3*sizeof(int*));
    for(int i=0;i<3;i++){
        arrptr2d[i] = (int*)malloc(4*sizeof(int*));
    }

    /*arr[i][j]       // typical
*(arr[i] + j)   // using pointer arithmetic
*(*(arr + i) + j)*/
    int count = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            arrptr2d[i][j] = count;
            count++;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout << arrptr2d[i][j] << " ";
        }
        cout << "\n";
    }

    int **arrptr2dn = new int*[3];
    for(int i=0;i<3;i++){
        arrptr2dn[i] =new int[4];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            *(arrptr2dn[i]+j) = count;
            count++;
        }
    }

    cout << "Print 2d array : new array " << endl;

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout <<  *(*(arrptr2dn+i)+j) << " ";
        }
        cout << "\n";
    }

    free(arrptr2d);
    delete[] arrptr2dn;

    char name[] = "suriya";
    char *c = name;
    while(*c!='\0'){
        cout << *c;
        c++;
    }
    cout << "\n";

    int array[] = {1,2,2,2,3,4};
    int *ar = array;
    for(int i=0;i<6;i++){
        cout << *ar << " ";
        ar++;
    }
    cout << "\n";

    int *a1 = (int*)malloc(10);// allocate 10 size
    int *a2 = (int*)calloc(10,10); // allocate 10 size and fill with zero
    a1 = (int*)realloc(a1,100); // reallocate 10 to 100

    free(a1);
    free(a2);
    return 0;
}