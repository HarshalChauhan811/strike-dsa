#include <iostream>
using namespace std;

int main() {

    // =====================================
    // Basic If Statement
    // =====================================

    int age = 20;

    if(age >= 18) {

        cout << "You are an adult" << endl;
    }


    // =====================================
    // If Else Statement
    // =====================================

    int age2 = 15;

    if(age2 >= 18) {

        cout << "You are an adult" << endl;
    }
    else {

        cout << "You are a minor" << endl;
    }


    // =====================================
    // If Else If Else
    // =====================================

    int marks = 85;

    if(marks >= 90) {

        cout << "Grade: A" << endl;
    }
    else if(marks >= 80) {

        cout << "Grade: B" << endl;
    }
    else if(marks >= 70) {

        cout << "Grade: C" << endl;
    }
    else if(marks >= 60) {

        cout << "Grade: D" << endl;
    }
    else {

        cout << "Grade: F" << endl;
    }


    // =====================================
    // Nested If
    // =====================================

    int userAge = 20;
    bool hasLicense = true;

    if(userAge >= 18) {

        if(hasLicense) {

            cout << "You can drive" << endl;
        }
        else {

            cout << "You need a license" << endl;
        }
    }
    else {

        cout << "You are too young" << endl;
    }

    return 0;
}