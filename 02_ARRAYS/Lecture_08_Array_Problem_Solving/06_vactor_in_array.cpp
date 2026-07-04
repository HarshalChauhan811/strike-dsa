#include <iostream>
#include <vector>   // Vector use karne ke liye ye header file include karni padti hai.
using namespace std;

int main() {

    // Vector Declaration

    vector<int> arr;


    // Vector me Elements Insert karna

    // push_back() hamesha last me element insert karta hai.

    arr.push_back(10);   // arr = [10]
    arr.push_back(20);   // arr = [10, 20]
    arr.push_back(30);   // arr = [10, 20, 30]
    arr.push_back(40);   // arr = [10, 20, 30, 40]


    // Last Element Remove karna

    // pop_back() sirf last element ko remove karta hai.

    arr.pop_back();      // arr = [10, 20, 30]


    // Vector ka Size check karna

    cout << "Size : " << arr.size() << endl;


    // Vector ke Elements Print karna

    cout << "Elements : ";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;


    // First aur Last Element Access karna

    cout << "First Element : " << arr.front() << endl;

    cout << "Last Element : " << arr.back() << endl;


    // Check karo Vector Empty hai ya nahi

    if (arr.empty()) {
        cout << "Vector is Empty" << endl;
    }
    else {
        cout << "Vector is Not Empty" << endl;
    }

    return 0;
}

/*
Output

Size : 3

Elements : 10 20 30

First Element : 10

Last Element : 30

Vector is Not Empty
*/