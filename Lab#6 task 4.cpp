#include <iostream>
using namespace std;

class Shape {
public:
    virtual double calculateArea() {
        return 0;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double Radius;
public:
    Circle(double r) {
        Radius = r;
    }
    double calculateArea()  {
        return 3.14159 * Radius * Radius;
    }
};

class Rectangle : public Shape {
private:
    double Length;
    double Width;
public:
    Rectangle(double l, double w) {
        Length = l;
        Width = w;
    }
    double calculateArea() override {
        return Length * Width;
    }
};

class Triangle : public Shape {
private:
    double Base;
    double Height;
public:
    Triangle(double b, double h) {
        Base = b;
        Height = h;
    }
    double calculateArea() override {
        return 0.5 * Base * Height;
    }
};

int main() {
    Shape* shape1 = new Circle(5);
    Shape* shape2 = new Rectangle(10, 4);
    Shape* shape3 = new Triangle(6, 8);

    cout << shape1->calculateArea() << endl;
    cout << shape2->calculateArea() << endl;
    cout << shape3->calculateArea() << endl;

    delete shape1;
    delete shape2;
    delete shape3;
}