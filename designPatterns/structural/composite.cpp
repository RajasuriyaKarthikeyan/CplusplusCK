#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*The Composite Pattern is a structural design pattern used to treat individual objects and groups of objects uniformly. 
It builds a tree-like structure of objects, where both single items and groups can be treated the same way.*/

// 1. Component
class FileSystemObject {
public:
    virtual void display(int indent = 0) = 0;
    virtual ~FileSystemObject() {}
};

// 2. Leaf
class File : public FileSystemObject {
    string name;
public:
    File(string n) : name(n) {}

    void display(int indent = 0) override {
        cout << string(indent, '-') << "File: " << name << endl;
    }
};

// 3. Composite
class Folder : public FileSystemObject {
    string name;
    vector<FileSystemObject*> children;
public:
    Folder(string n) : name(n) {}

    void add(FileSystemObject* obj) {
        children.push_back(obj);
    }

    void display(int indent = 0) override {
        cout << string(indent, '-') << "Folder: " << name << endl;
        for (auto child : children) {
            child->display(indent + 2);
        }
    }

    ~Folder() {
        for (auto child : children) delete child;
    }
};

// 4. Client
int main() {
    Folder* root = new Folder("Root");
    root->add(new File("file1.txt"));
    root->add(new File("file2.txt"));

    Folder* subFolder = new Folder("SubFolder");
    subFolder->add(new File("file3.txt"));
    root->add(subFolder);

    root->display();

    delete root;
    return 0;
}
