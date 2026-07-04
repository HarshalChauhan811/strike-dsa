#include <iostream>
using namespace std;

// Linear Search

// Array ke har element ko
// ek-ek karke check karte hain.

// Agar target mil jaye
// to uska index return kar dete hain.

// Agar target na mile
// to -1 return karte hain.

int linearSearch(int arr[], int n, int target) {

    // Array ke saare elements ko traverse karo
    for (int i = 0; i < n; i++) {

        // Agar target mil gaya
        if (arr[i] == target) {
            return i;
        }
    }

    // Target array me nahi mila
    return -1;
}

int main() {

    int arr[5] = {2, 4, 5, 8, 10};
    int target = 10;

    // Function Call
    int result = linearSearch(arr, 5, target);

    if (result == -1) {
        cout << "Element is not present in the Array." << endl;
    }
    else {
        cout << "Element found at Index : " << result << endl;
    }

    return 0;
}

