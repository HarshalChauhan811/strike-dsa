#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Basic While Loop
    // =====================================

    int i = 1;

    while(i <= 5) {

        cout << i << endl;

        i++;
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
    // User Input Until Correct
    // =====================================

    int password;
    int correctPassword = 1234;

    cout << "Enter password: ";
    cin >> password;

    while(password != correctPassword) {

        cout << "Wrong! Try again: ";
        cin >> password;
    }

    cout << "Access granted!" << endl;


    // =====================================
    // Sum Until User Enters 0
    // =====================================

    int num;
    int sum = 0;

    cout << "Enter numbers (0 to stop):" << endl;

    while(true) {

        cin >> num;

        // Exit loop if user enters 0
        if(num == 0) {

            break;
        }

        sum += num;
    }

    cout << "Total sum: " << sum << endl;

    return 0;
}