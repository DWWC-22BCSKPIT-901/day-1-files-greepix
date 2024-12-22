#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Input: Read the value of n
    cout << "Enter the value of n: ";
    cin >> n;
    
    // Calculate the sum using the formula
    int sum_of_natural_numbers = n * (n + 1) / 2;
    
    // Output: Print the result
    cout << sum_of_natural_numbers << endl;
    
    return 0;
}
