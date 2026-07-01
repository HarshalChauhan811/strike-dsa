#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Basic Do While Loop
    // =====================================

    int i = 1;

    do {

        cout << i << endl;

        i++;

    } while(i <= 5);

    /*
    Output:
    1
    2
    3
    4
    5
    */


    // =====================================
    // while vs do while
    // =====================================

    int x = 10;

    // while loop

    while(x <= 5) {

        cout << x << endl;
    }

    /*
    Output:
    Nothing
    */


    // do while loop

    do {

        cout << x << endl;

    } while(x <= 5);

    /*
    Output:
    10
    */

    return 0;
}