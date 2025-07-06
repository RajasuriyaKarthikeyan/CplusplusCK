#include <iostream>
using namespace std;

/*The Bridge Pattern is a structural design pattern that lets you separate an abstraction from its implementation 
so that the two can vary independently.*/

// 1. Implementor
class DrawAPI {
public:
    virtual void drawCircle(int x, int y, int radius) = 0;
    virtual ~DrawAPI() = default;
};

// 2. ConcreteImplementors
class RedDrawAPI : public DrawAPI {
public:
    void drawCircle(int x, int y, int radius) override {
        cout << "Drawing Red Circle at (" << x << "," << y << ") with radius " << radius << endl;
    }
};

class GreenDrawAPI : public DrawAPI {
public:
    void drawCircle(int x, int y, int radius) override {
        cout << "Drawing Green Circle at (" << x << "," << y << ") with radius " << radius << endl;
    }
};

// 3. Abstraction
class Shape {
protected:
    DrawAPI* drawAPI;
public:
    Shape(DrawAPI* api) : drawAPI(api) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// 4. Refined Abstraction
class Circle : public Shape {
    int x, y, radius;
public:
    Circle(int x, int y, int r, DrawAPI* api) : Shape(api), x(x), y(y), radius(r) {}

    void draw() override {
        drawAPI->drawCircle(x, y, radius);
    }
};

// 5. Client
int main() {
    DrawAPI* redAPI = new RedDrawAPI();
    DrawAPI* greenAPI = new GreenDrawAPI();

    Shape* redCircle = new Circle(10, 20, 5, redAPI);
    Shape* greenCircle = new Circle(30, 40, 10, greenAPI);

    redCircle->draw();   // Drawing Red Circle
    greenCircle->draw(); // Drawing Green Circle

    // Cleanup
    delete redCircle;
    delete greenCircle;
    delete redAPI;
    delete greenAPI;

    return 0;
}
