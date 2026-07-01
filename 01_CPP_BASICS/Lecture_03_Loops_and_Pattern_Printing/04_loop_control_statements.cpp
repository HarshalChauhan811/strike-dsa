#include <iostream>
using namespace std;

int main() {

    // =====================================
    // break Statement
    // =====================================

    for(int i = 1; i <= 10; i++) {

        // Stop loop when i becomes 5
        if(i == 5) {

            break;
        }

        cout << i << " ";
    }

    /*
    Output:
    1 2 3 4
    */

    cout << endl;


    // =====================================
    // continue Statement
    // =====================================

    for(int i = 1; i <= 5; i++) {

        // Skip number 3
        if(i == 3) {

            continue;
        }

        cout << i << " ";
    }

    /*
    Output:
    1 2 4 5
    */

    cout << endl;


    // =====================================
    // Skip Even Numbers
    // =====================================

    for(int i = 1; i <= 10; i++) {

        // Skip even numbers
        if(i % 2 == 0) {

            continue;
        }

        cout << i << " ";
    }

    /*
    Output:
    1 3 5 7 9
    */

    return 0;
}