#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Pattern 1 : Square Pattern
    // =====================================

    for(int i = 1; i <= 5; i++) {

        for(int j = 1; j <= 5; j++) {

            cout << "*";
        }

        cout << endl;
    }

    /*
    Output:
    *****
    *****
    *****
    *****
    *****
    */

    cout << endl;


    // =====================================
    // Pattern 2 : Right Triangle
    // =====================================

    for(int i = 1; i <= 5; i++) {

        for(int j = 1; j <= i; j++) {

            cout << "*";
        }

        cout << endl;
    }

    /*
    Output:
    *
    **
    ***
    ****
    *****
    */

    cout << endl;


    // =====================================
    // Pattern 3 : Reverse Triangle
    // =====================================

    for(int i = 5; i >= 1; i--) {

        for(int j = 1; j <= i; j++) {

            cout << "*";
        }

        cout << endl;
    }

    /*
    Output:
    *****
    ****
    ***
    **
    *
    */

    cout << endl;


    // =====================================
    // Pattern 4 : Inverted Triangle
    // =====================================

    for(int i = 1; i <= 5; i++) {

        // Print spaces

        for(int j = 1; j <= 5 - i; j++) {

            cout << " ";
        }

        // Print stars

        for(int j = 1; j <= i; j++) {

            cout << "*";
        }

        cout << endl;
    }

    /*
    Output:
        *
       **
      ***
     ****
    *****
    */

    cout << endl;


    // =====================================
    // Pattern 5 : Number Square Pattern
    // =====================================

    int num = 1;

    for(int i = 1; i <= 5; i++) {

        for(int j = 1; j <= 5; j++) {

            cout << num << " ";

            num++;
        }

        cout << endl;
    }

    /*
    Output:
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25
    */

    return 0;
}