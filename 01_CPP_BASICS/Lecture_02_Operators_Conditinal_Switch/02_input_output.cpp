#include <iostream>
using namespace std;

int main() {

    // Variables

    string name;
    int age;

    // Taking Input

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    // Output

    cout << "\nHello " << name << "!" << endl;
    cout << "You are " << age << " years old." << endl;

    return 0;
}