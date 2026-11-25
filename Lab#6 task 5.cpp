#include <iostream>
using namespace std;

class Account {
protected:
    double Balance;
public:
    Account(double b) {
        Balance = b;
    }
    virtual void deposit(double amount) {
        if (amount > 0) Balance += amount;
    }
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= Balance) Balance -= amount;
    }
    double getBalance() {
        return Balance;
    }
    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {
    }
    void deposit(double amount) override {
        if (amount > 0) {
            Balance += amount;
        }
    }
    void withdraw(double amount) override {
        if (amount > 0 && amount <= Balance) {
            Balance -= amount;
        }
    }
};

int main() {
    Account* account = new SavingsAccount(10000);

    account->deposit(2000);
    cout << account->getBalance() << endl;

    account->withdraw(3000);
    cout << account->getBalance() << endl;

    delete account;
}