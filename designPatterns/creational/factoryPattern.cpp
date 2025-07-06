#include <iostream>
#include <string>

/*Factory Method Pattern provides an interface for creating objects but leaves the actual object instantiation to derived classes.
 This allows for flexibility in object creation and promotes loose coupling between the client code and the concrete products.*/

using namespace std;

//Product
class Shape{
    public:
        virtual void draw() = 0;
        virtual ~Shape(){};
};

// Concrete product
class rectangle: public Shape{
    public:
        void draw() override{
            cout << "Drawing Rectangle" << endl;
        }
};

class circle: public Shape{
    public:
        void draw() override{
            cout << "Drawing Circle" << endl;
        }
};

// Creator
class ShapeFactory{
    public:
        virtual Shape* createShape() = 0;
        virtual ~ShapeFactory(){};
};

// Concrete Creator
class RectangleFactory: public ShapeFactory{
    public:
        Shape* createShape() override{
            return new rectangle();
        }
};

class CircleFactory: public ShapeFactory{
    public:
        Shape* createShape() override{
            return new circle();
        }
};

int main(){
    string s;
    cout << "Enter the Shape (circle or rectangle) : ";
    cin >> s;
    ShapeFactory *shapeF = nullptr;
    if(s == "circle"){
        shapeF = new CircleFactory();
    } else if (s == "rectangle"){
        shapeF = new RectangleFactory();
    } else {
        cout << "Invalid Shape Entered ..." << endl;
        return 0;
    }

    Shape *sha = shapeF->createShape();
    sha->draw();
    
    delete shapeF;
    delete sha;

}

