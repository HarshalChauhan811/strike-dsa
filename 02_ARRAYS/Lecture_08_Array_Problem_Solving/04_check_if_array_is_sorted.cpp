#include <iostream>
using namespace std;

// Check Array is Sorted or Not

// Agar har element apne pichhle element
// se bada ya equal hai,
// to array sorted hai.

bool isSorted(int arr[], int n) {

    // Index 1 se start karenge
    // kyunki pehle element ka koi previous element nahi hota.

    for (int i = 1; i < n; i++) {

        // Agar current element
        // previous element se chhota mil gaya
        // to array sorted nahi hai.

        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    // Agar poora loop complete ho gaya
    // to array sorted hai.

    return true;
}

int main() {

    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5] = {50, 40, 30, 20, 10};

    cout << "arr1 Sorted? "
         << (isSorted(arr1, 5) ? "Yes" : "No")
         << endl;

    cout << "arr2 Sorted? "
         << (isSorted(arr2, 5) ? "Yes" : "No")
         << endl;

    return 0;
}

/*
Dry Run

arr = [10, 20, 30, 40, 50]

i = 1

20 > 10

Continue

i = 2

30 > 20

Continue

i = 3

40 > 30

Continue

i = 4

50 > 40

Continue

Loop Complete

Array is Sorted.


Example 2

arr = [50, 40, 30, 20, 10]

i = 1

40 < 50

Return false

*/

