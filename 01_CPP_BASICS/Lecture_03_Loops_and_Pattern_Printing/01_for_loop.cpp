#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Basic For Loop
    // =====================================

    // Print numbers from 1 to 5

    for(int i = 1; i <= 5; i++) {

        cout << i << endl;
    }

    /*
    Output:
    1
    2
    3
    4
    5
    */


    // =====================================
    // Print Even Numbers
    // =====================================

    for(int i = 2; i <= 10; i += 2) {

        cout << i << " ";
    }

    /*
    Output:
    2 4 6 8 10
    */

    cout << endl;


    // =====================================
    // Sum of First 10 Numbers
    // =====================================

    int sum = 0;

    for(int i = 1; i <= 10; i++) {

        sum = sum + i;
    }

    cout << "Sum: " << sum << endl;

    /*
    Output:
    Sum: 55
    */


    // =====================================
    // Multiplication Table
    // =====================================

    int num = 5;

    cout << "Multiplication table of " << num << endl;

    for(int i = 1; i <= 10; i++) {

        cout << num << " x " << i
             << " = "
             << (num * i)
             << endl;
    }

    /*
    Output:
    5 x 1 = 5
    5 x 2 = 10
    ...
    5 x 10 = 50
    */


    // =====================================
    // Reverse Counting
    // =====================================

    for(int i = 10; i >= 1; i--) {

        cout << i << " ";
    }

    /*
    Output:
    10 9 8 7 6 5 4 3 2 1
    */

    return 0;
}