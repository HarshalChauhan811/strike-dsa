#include <iostream>
using namespace std;

/*
====================================================
Problem --> Find Highest Element in Array

Input  : [70, 30, 40, 30, 20]
Output : Highest Element : 70

Approach
1. First element ko highest maan lo.
2. Pure array ko traverse karo.
3. Agar koi bada element mile to highest update kar do.
4. Last me highest print kar do.

Time Complexity  : O(n)
Space Complexity : O(1)
====================================================
*/

int main() {

    int arr[] = {70, 30, 40, 30, 20};

    int highest = arr[0];   // first element ko highest maan liya

    for (int i = 0; i < 5; i++) {

        if (arr[i] > highest) {
            highest = arr[i];   // bada mila to update
        }

    }

    cout << "Highest Element : " << highest;

    return 0;
}

/*
====================
Dry Run

Array : [70,30,40,30,20]

highest = 70

30 > 70 -> No
40 > 70 -> No
30 > 70 -> No
20 > 70 -> No

Answer = 70
====================
*/