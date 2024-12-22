#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;
    double salary;
public:
    Employee(string empName, int empId, double empSalary) 
        : name(empName), id(empId), salary(empSalary) {}

    virtual void calculateEarnings() = 0; // Pure virtual function
    virtual ~Employee() {}
};

// Derived class for Manager
class Manager : public Employee {
    int performanceRating;
public:
    Manager(string empName, int empId, double empSalary, int rating) 
        : Employee(empName, empId, empSalary), performanceRating(rating) {}

    void calculateEarnings() override {
        double bonus = 0;
        if (performanceRating == 5) bonus = salary * 0.20;
        else if (performanceRating == 4) bonus = salary * 0.10;
        else if (performanceRating == 3) bonus = salary * 0.05;

        cout << fixed << setprecision(2)
             << "Manager Details:\nName: " << name
             << "\nID: " << id
             << "\nBase Salary: $" << salary
             << "\nPerformance Bonus: $" << bonus
             << "\nTotal Earnings: $" << (salary + bonus) << endl;
    }
};

// Derived class for Developer
class Developer : public Employee {
    int extraHours;
public:
    Developer(string empName, int empId, double empSalary, int hours) 
        : Employee(empName, empId, empSalary), extraHours(hours) {}

    void calculateEarnings() override {
        double overtimeCompensation = extraHours * 20; // $20 per extra hour
        cout << fixed << setprecision(2)
             << "Developer Details:\nName: " << name
             << "\nID: " << id
             << "\nBase Salary: $" << salary
             << "\nOvertime Compensation: $" << overtimeCompensation
             << "\nTotal Earnings: $" << (salary + overtimeCompensation) << endl;
    }
};

int main() {
    cout << "Choose Employee Type:\n1. Manager\n2. Developer\n";
    int choice;
    cin >> choice;

    string name;
    int id, salary;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Salary: ";
    cin >> salary;

    if (choice == 1) {
        int performanceRating;
        cout << "Enter Performance Rating (1-5): ";
        cin >> performanceRating;

        Manager mgr(name, id, salary, performanceRating);
        mgr.calculateEarnings();
    } 
    else if (choice == 2) {
        int extraHours;
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;

        Developer dev(name, id, salary, extraHours);
        dev.calculateEarnings();
    } 
    else {
        cout << "Invalid employee type selected!" << endl;
    }

    return 0;
}
