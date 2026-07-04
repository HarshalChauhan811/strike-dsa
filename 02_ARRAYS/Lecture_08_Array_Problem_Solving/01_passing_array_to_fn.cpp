#include <iostream>
using namespace std;

// Array ko Function me pass kar rahe hain.

// Array jab Function me pass hota hai
// to uska base address pass hota hai.

// Isliye Function ke andar kiye gaye changes
// Original Array me bhi reflect hote hain.

// Isi wajah se Array ko
// Pass by Reference jaisa behaviour milta hai.

void printValue(int arr[], int n) {

    // Array ke saare elements print karo
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Original Array ko modify kar rahe hain
    arr[0] = 100;
}

int main() {

    int arr[5] = {10, 20, 30, 40, 50};

    // Function Call
    printValue(arr, 5);

    // Function ke baad bhi change reflect hoga
    cout << arr[0] << endl;

    return 0;
}