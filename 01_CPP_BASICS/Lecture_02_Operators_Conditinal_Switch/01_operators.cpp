#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Arithmetic Operators
    // =====================================

    int a = 10, b = 3;

    cout << a + b << endl;   // 13
    cout << a - b << endl;   // 7
    cout << a * b << endl;   // 30
    cout << a / b << endl;   // 3
    cout << a % b << endl;   // 1


    // Example

    int marks1 = 80, marks2 = 90;

    int total = marks1 + marks2;
    int average = total / 2;

    cout << "Total: " << total << endl;        // 170
    cout << "Average: " << average << endl;    // 85


    // =====================================
    // Assignment Operators
    // =====================================

    int x = 10;

    x = 5;
    x += 3;
    x -= 2;
    x *= 4;
    x /= 2;

    cout << x << endl; // 12


    // =====================================
    // Comparison Operators
    // =====================================

    int p = 10, q = 5;

    cout << (p == q) << endl;   // false = 0
    cout << (p != q) << endl;   // true = 1
    cout << (p > q) << endl;    // true = 1
    cout << (p < q) << endl;    // false = 0
    cout << (p >= q) << endl;   // true = 1
    cout << (p <= q) << endl;   // false = 0


    // =====================================
    // Logical Operators
    // =====================================

    int age = 20;
    bool hasLicense = true;

    // AND Operator

    if(age >= 18 && hasLicense) {

        cout << "Can drive!" << endl;
    }

    // OR Operator

    cout << (true || false) << endl; // 1

    // NOT Operator

    cout << !true << endl; // 0


    // =====================================
    // Increment / Decrement
    // =====================================

    int score = 0;

    score++;
    score++;
    score++;

    cout << score << endl; // 3

    score--;

    cout << score << endl; // 2


    // =====================================
    // Bitwise Operators
    // =====================================

    int m = 5, n = 3;

    cout << (m & n) << endl;   // 1
    cout << (m | n) << endl;   // 7
    cout << (m ^ n) << endl;   // 6
    cout << (~m) << endl;      // -6


    // =====================================
    // Shift Operators
    // =====================================

    int num = 5;

    // Left Shift

    cout << (num << 1) << endl; // 10
    cout << (num << 2) << endl; // 20

    // Right Shift

    cout << (num >> 1) << endl; // 2
    cout << (num >> 2) << endl; // 1


    // Example

    int salary = 1000;

    cout << (salary << 1) << endl; // 2000
    cout << (salary >> 1) << endl; // 500

    return 0;
}