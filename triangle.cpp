#include <iostream>
using namespace std;

void verify(int a, int b, int c) {
    if (a + b > c && b + c > a && c + a > b) {
        if (a == b && b == c) {
            cout << "Equilateral triangle" << endl;
        } else if (a == b || b == c || a == c) {
            cout << "Isosceles triangle" << endl;
        } else {
            cout << "Scalene triangle" << endl;
        }
    } else {
        cout << "Triangle cannot be formed" << endl;
    }
}

int main() {
    int a, b, c;
    cout << "Input the sides of the triangle: ";
    cin >> a >> b >> c;

    verify(a, b, c); // Call the verify function with the input values

    return 0; // Return statement to indicate successful execution
}
