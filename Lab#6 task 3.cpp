#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string Brand;
    string Model;
public:
    Vehicle(string b = "", string m = "") {
        Brand = b;
        Model = m;
    }
    virtual void displayInfo() {
        cout << "Brand: " << Brand << endl;
        cout << "Model: " << Model << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int NumberOfDoors;
public:
    Car(string b, string m, int d) : Vehicle(b, m) {
        NumberOfDoors = d;
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Number of Doors: " << NumberOfDoors << endl;
    }
};

int main() {
    Vehicle* vehicle = new Car("Toyota", "Corolla", 4);
    vehicle->displayInfo();
    delete vehicle;
}