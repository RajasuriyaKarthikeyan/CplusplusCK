#include <iostream>
#include <fstream>

using namespace std;


class FileHandling{
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
            ifstream inFile(fileName);
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
            ofstream file(fileName, ios::app); // Open in append mode

            if (file.is_open()) {
                file << "Appended line." << endl;
                file.close();
            } else {
                cout << "Unable to open file." << endl;
            }
        }
};
int main(){
    FileHandling f1;
    f1.Write("SuriyaFile.txt");
    f1.Read("SuriyaFile.txt");
    f1.EditFile("SuriyaFile.txt");
    f1.Read("SuriyaFile.txt");
}