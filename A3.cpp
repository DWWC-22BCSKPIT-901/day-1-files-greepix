#include <iostream>
#include <cmath>
using namespace std;

// Overloaded function to calculate the area of a circle
double area(double radius) {
    return M_PI * radius * radius;
}

// Overloaded function to calculate the area of a rectangle
double area(double length, double breadth) {
    return length * breadth;
}

// Overloaded function to calculate the area of a triangle
double area(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    cout << "Choose a shape to calculate area:\n";
    cout << "1. Circle\n2. Rectangle\n3. Triangle\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            cout << "Area of the circle: " << area(radius) << endl;
            break;
        }
        case 2: {
            double length, breadth;
            cout << "Enter the length and breadth of the rectangle: ";
            cin >> length >> breadth;
            cout << "Area of the rectangle: " << area(length, breadth) << endl;
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter the base and height of the triangle: ";
            cin >> base >> height;
            cout << "Area of the triangle: " << area(base, height, true) << endl;
            break;
        }
        default:
            cout << "Invalid choice! Please select a valid option.\n";
    }
    return 0;
}
