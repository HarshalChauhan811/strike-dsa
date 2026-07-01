#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Problem 1 : Even or Odd
    // =====================================

    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(num % 2 == 0) {

        cout << num << " is even" << endl;
    }
    else {

        cout << num << " is odd" << endl;
    }


    // =====================================
    // Problem 2 : Maximum of Two Numbers
    // =====================================

    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    if(a > b) {

        cout << a << " is maximum" << endl;
    }
    else {

        cout << b << " is maximum" << endl;
    }


    // =====================================
    // Problem 3 : Positive Negative Zero
    // =====================================

    int value;

    cout << "Enter a number: ";
    cin >> value;

    if(value > 0) {

        cout << "Positive" << endl;
    }
    else if(value < 0) {

        cout << "Negative" << endl;
    }
    else {

        cout << "Zero" << endl;
    }


    // =====================================
    // Problem 4 : Calculator
    // =====================================

    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    if(op == '+') {

        cout << "Result: " << (num1 + num2) << endl;
    }
    else if(op == '-') {

        cout << "Result: " << (num1 - num2) << endl;
    }
    else if(op == '*') {

        cout << "Result: " << (num1 * num2) << endl;
    }
    else if(op == '/') {

        if(num2 != 0) {

            cout << "Result: " << (num1 / num2) << endl;
        }
        else {

            cout << "Cannot divide by zero!" << endl;
        }
    }
    else {

        cout << "Invalid operator!" << endl;
    }


    // =====================================
    // Problem 5 : Grade Calculator
    // =====================================

    int marks;

    cout << "Enter your marks (0-100): ";
    cin >> marks;

    if(marks > 100 || marks < 0) {

        cout << "Invalid marks!" << endl;
    }
    else if(marks >= 90) {

        cout << "Grade: A (Excellent)" << endl;
    }
    else if(marks >= 80) {

        cout << "Grade: B (Very Good)" << endl;
    }
    else if(marks >= 70) {

        cout << "Grade: C (Good)" << endl;
    }
    else if(marks >= 60) {

        cout << "Grade: D (Satisfactory)" << endl;
    }
    else {

        cout << "Grade: F (Fail)" << endl;
    }

    return 0;
}