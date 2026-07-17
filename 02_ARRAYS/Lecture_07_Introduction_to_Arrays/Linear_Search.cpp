#include <iostream>
using namespace std;

/*
====================================================
Problem --> Linear Search in Array

Definition
Linear Search me hum array ke har element ko
ek-ek karke check karte hain jab tak element
mil na jaye ya pura array khatam na ho jaye.

----------------------------------------------------
Example 1

Input
Array  : [10, 20, 30, 40, 50]
Search : 30

Output
Search Element : 30
Index : 2

----------------------------------------------------
Example 2

Input
Array  : [5, 15, 25, 35]
Search : 5

Output
Search Element : 5
Index : 0

----------------------------------------------------
Example 3

Input
Array  : [10, 70, 56, 80, 90]
Search : 40

Output
Element is not present in the Array

----------------------------------------------------
Approach

1. Start se array traverse karo.
2. Har element ko search value se compare karo.
3. Match milte hi element aur index print kar do.
4. Agar pura array check ho jaye aur match na mile,
   to "Element is not present" print kar do.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

int main() {

    int arr[] = {10, 70, 56, 80, 90};

    int search = 40;
    bool found = false;

    for (int i = 0; i < 5; i++) {

        if (arr[i] == search) {

            cout << "Search Element : " << arr[i] << endl;
            cout << "Index : " << i << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element is not present in the Array";
    }

    return 0;
}

/*
====================
Dry Run

Array  : [10, 70, 56, 80, 90]
Search : 40

i = 0 -> 10 != 40
i = 1 -> 70 != 40
i = 2 -> 56 != 40
i = 3 -> 80 != 40
i = 4 -> 90 != 40

Element Not Found

Output
Element is not present in the Array

====================
*/