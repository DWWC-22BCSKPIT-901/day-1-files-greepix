#include <iostream>
#include <iomanip>
using namespace std;

// Base class
class Account {
protected:
    double balance;
public:
    Account(double bal) : balance(bal) {}
    virtual void calculateInterest() = 0; // Pure virtual method
    virtual ~Account() {}
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
    double rate;
    int time;
public:
    SavingsAccount(double bal, double r, int t) : Account(bal), rate(r / 100), time(t) {}
    void calculateInterest() override {
        double interest = balance * rate * time;
        cout << fixed << setprecision(2) 
             << "Savings Account Interest: " << interest 
             << "\nFinal Balance: " << balance + interest << endl;
    }
};

// Derived class for CurrentAccount
class CurrentAccount : public Account {
    double maintenanceFee;
public:
    CurrentAccount(double bal, double fee) : Account(bal), maintenanceFee(fee) {}
    void calculateInterest() override {
        double deductions = maintenanceFee * 12;
        cout << fixed << setprecision(2)
             << "No Interest for Current Account.\nYearly Maintenance Deduction: " 
             << deductions 
             << "\nFinal Balance: " << balance - deductions << endl;
    }
};

int main() {
    cout << "Choose Account Type:\n1. Savings Account\n2. Current Account\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        double balance, rate;
        int time;
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Interest Rate (in %): ";
        cin >> rate;
        cout << "Enter Time (in years): ";
        cin >> time;

        SavingsAccount sa(balance, rate, time);
        sa.calculateInterest();
    } else if (choice == 2) {
        double balance, maintenanceFee;
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> maintenanceFee;

        CurrentAccount ca(balance, maintenanceFee);
        ca.calculateInterest();
    } else {
        cout << "Invalid account type selected!" << endl;
    }

    return 0;
}
