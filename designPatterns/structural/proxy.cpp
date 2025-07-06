#include <iostream>
#include <string>
using namespace std;

/*
The Proxy Pattern is a structural design pattern that provides a placeholder or surrogate for another object to control access to it.
*/

// 1. Subject
class Document {
public:
    virtual void display() = 0;
    virtual ~Document() {}
};

// 2. RealSubject
class RealDocument : public Document {
    string content;
public:
    RealDocument(string data) : content(data) {}
    void display() override {
        cout << "Displaying Document: " << content << endl;
    }
};

// 3. Proxy
class DocumentProxy : public Document {
    RealDocument* realDoc;
    string userRole;
public:
    DocumentProxy(string role, string content) : userRole(role), realDoc(nullptr) {
        if (userRole == "admin") {
            realDoc = new RealDocument(content);
        }
    }

    void display() override {
        if (userRole == "admin") {
            realDoc->display();
        } else {
            cout << "Access Denied: Insufficient permissions.\n";
        }
    }

    ~DocumentProxy() {
        delete realDoc;
    }
};

// 4. Client
int main() {
    Document* adminView = new DocumentProxy("admin", "Top Secret Report");
    adminView->display();  // Has access

    Document* guestView = new DocumentProxy("guest", "Top Secret Report");
    guestView->display();  // Access Denied

    delete adminView;
    delete guestView;
    return 0;
}
