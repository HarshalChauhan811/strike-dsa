#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Switch Statement
    // =====================================

    int day = 3;

    switch(day) {

        case 1:
            cout << "Monday" << endl;
            break;

        case 2:
            cout << "Tuesday" << endl;
            break;

        case 3:
            cout << "Wednesday" << endl;
            break;

        case 4:
            cout << "Thursday" << endl;
            break;

        case 5:
            cout << "Friday" << endl;
            break;

        case 6:
            cout << "Saturday" << endl;
            break;

        case 7:
            cout << "Sunday" << endl;
            break;

        default:
            cout << "Invalid day" << endl;
    }

    // Output:
    // Wednesday



    // =====================================
    // Switch Calculator
    // =====================================

    char op;
    double a, b;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    switch(op) {

        case '+':
            cout << "Result: " << (a + b) << endl;
            break;

        case '-':
            cout << "Result: " << (a - b) << endl;
            break;

        case '*':
            cout << "Result: " << (a * b) << endl;
            break;

        case '/':

            if(b != 0) {

                cout << "Result: " << (a / b) << endl;
            }
            else {

                cout << "Cannot divide by zero!" << endl;
            }

            break;

        default:
            cout << "Invalid operator" << endl;
    }



    // =====================================
    // Break Statement
    // =====================================

    int num = 2;

    switch(num) {

        case 1:
            cout << "One" << endl;

        case 2:
            cout << "Two" << endl;

        case 3:
            cout << "Three" << endl;

        default:
            cout << "Other" << endl;
    }

    // Output:
    // Two
    // Three
    // Other



    // =====================================
    // With Break
    // =====================================

    switch(num) {

        case 1:
            cout << "One" << endl;
            break;

        case 2:
            cout << "Two" << endl;
            break;

        case 3:
            cout << "Three" << endl;
            break;

        default:
            cout << "Other" << endl;
    }

    // Output:
    // Two



    // =====================================
    // Continue Statement
    // =====================================

    for(int i = 1; i <= 5; i++) {

        if(i == 3) {

            continue;
        }

        cout << i << " ";
    }

    // Output:
    // 1 2 4 5

    return 0;
}