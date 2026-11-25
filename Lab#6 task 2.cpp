#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string Name;
    double Salary;
public:
    Employee(string n = "", double s = 0.0) {
        Name = n;
        Salary = s;
    }
    virtual void displayInfo() {
        cout << "Name: " << Name << endl;
        cout << "Salary: " << Salary << endl;
    }
    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    string Department;
public:
    Manager(string n, double s, string d) : Employee(n, s) {
        Department = d;
    }
    void displayInfo() override {
        Employee::displayInfo();
        cout << "Department: " << Department << endl;
    }
};

int main() {
    Employee* employee = new Manager("Usman", 75000, "IT");
    employee->displayInfo();
    delete employee;
}