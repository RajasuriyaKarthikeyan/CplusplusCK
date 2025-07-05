#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        int id;
        string name;
    public:
        static int countObj;
        Student(){
            countObj++;
        }
        void getInfo(int id, string name){
            this->id = id;
            this->name = name;
        }

        void provideInfo(){
            cout << "Id : " << id << endl;
            cout << "Name : " << name << endl;
        }

        static int ObjectCount(){
            return countObj;
        }
};
int Student::countObj=0;

int main(){
    Student s;
    cout << "Size of class : " << sizeof(Student) << endl;
    s.getInfo(101, "Suriya");
    s.provideInfo();
    Student *s1 = new Student();
    s.getInfo(102, "Raja");
    s.provideInfo();
    cout << "Total object created so far " << Student::countObj << endl;
    delete s1;

    Student *stu = new Student[10];
    string nam = "S";
    for(int i=0;i<10;i++){
        stu[i].getInfo(i,nam);
        nam += "S";
        stu[i].provideInfo();
    }
    stu->provideInfo();
    Student s2 = stu[2]; // create obj and copies its value
    s2.provideInfo();
    cout << "Total object created so far post s1 deletion " << Student::countObj << endl;
    delete[] stu;
    s2.provideInfo();
    cout << "Object to be destroyed : " << s.ObjectCount << endl;
    return 0;
}