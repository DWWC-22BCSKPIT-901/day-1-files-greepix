#include <iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        n /= 10; // Remove the last digit
        count++; // Increment the count
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
    } else {
        int digitCount = countDigits(n);
        cout << "The total number of digits in " << n << " is: " << digitCount << endl;
    }

    return 0;
}
