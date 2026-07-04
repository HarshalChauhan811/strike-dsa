#include <iostream>
using namespace std;

// Reverse Array

// Array ko reverse karne ke liye
// first element ko last element se,
// second ko second last se
// swap karte hain.

void reverseArray(int arr[], int n) {

    // Sirf n/2 tak hi loop chalega.

    // Agar poora array traverse karenge
    // to elements dobara swap ho jayenge
    // aur array wapas original ban jayega.

    for (int i = 0; i < n / 2; i++) {

        // Current element ko
        // uske opposite element se swap karo.

        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {

    int arr[5] = {10, 15, 18, 22, 28};

    cout << "Before Reversing : ";

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Function Call
    reverseArray(arr, 5);

    cout << "After Reversing : ";

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
Dry Run

Array = [10, 15, 18, 22, 28]

i = 0

10 <-> 28

[28, 15, 18, 22, 10]

i = 1

15 <-> 22

[28, 22, 18, 15, 10]

i = 2

Loop Stop

Final Answer

[28, 22, 18, 15, 10]

*/
