#include <iostream>
#include <fstream>

using namespace std;


class FileHandline{
    public:
        void Write(string fileName){
            ofstream outFile(fileName);
            if (!outFile) {
                cerr << "File couldn't be opened for writing!" << endl;
                return ;
            }

            outFile << "Hello, File!" << endl;
            outFile << "Welcome to file handling in C++!" << endl;

            outFile.close();  // Always close the file
        }

        void Read(string fileName){
            ifstream inFile("example.txt");
            string line;

            if (!inFile) {
                cerr << "File couldn't be opened for reading!" << endl;
                return ;
            }

            while (getline(inFile, line)) {
                cout << line << endl;
            }

            inFile.close();
        }

        void EditFile(string fileName){

        }
};
int main(){

}