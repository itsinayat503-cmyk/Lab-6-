#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string Name;
    int Age;
public:
    Person(string n, int a) {
        Name = n;
        Age = a;
    }
    ~Person() {}
    virtual void displayInfo() {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
    }
    
};

class Student : public Person {
private:
    int RollNo;
    double Marks;
public:
    Student(string n, int a, int r, double m) : Person(n, a) {
        RollNo = r;
        Marks = m;
    }
    void displayInfo() override {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        //Person::displayInfo();
        cout << "Roll No: " << RollNo << endl;
        cout << "Marks: " << Marks << endl;
    }
};

int main() {
    Person* person = new Student("Ali", 20, 101, 88.5);
    person->displayInfo();
    delete person;
}