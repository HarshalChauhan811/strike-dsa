#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Second Largest Element
====================================================

GFG : Second Largest

====================================================
Definition

Array me Largest Element ke baad jo
sabse bada distinct element hota hai,
use Second Largest Element kehte hain.

Agar Second Largest exist na kare,
to -1 return karo.

====================================================
Example 1

Input

arr = [12,35,1,10,34,1]

Output

34

Explanation

Largest = 35

Second Largest = 34

----------------------------------------------------
Example 2

Input

arr = [10,10,10]

Output

-1

Explanation

Sabhi elements same hain,
isliye Second Largest exist nahi karta.

----------------------------------------------------
Example 3

Input

arr = [5,8,2,6]

Output

6

Explanation

Largest = 8

Second Largest = 6

====================================================
Approach --> Two Traversals (Without Sorting)

1. Pehle Largest Element find karo.
2. Fir dubara array traverse karo.
3. Largest se chhota aur
   sabse bada element hi
   Second Largest hoga.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    int getSecondLargest(vector<int> &arr) {

        int n = arr.size();

        // Largest Element
        int largest = arr[0];

        for (int i = 1; i < n; i++) {

            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        // Second Largest
        int secondLargest = -1;

        for (int i = 0; i < n; i++) {

            if (arr[i] < largest &&
                arr[i] > secondLargest) {

                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};

/*
====================================================
Dry Run

Input

arr = [12,35,1,10,34,1]

---------------------------------
Step 1

Largest = 12

35 > 12

Largest = 35

1 > 35 -> No

10 > 35 -> No

34 > 35 -> No

1 > 35 -> No

Largest = 35

---------------------------------
Step 2

SecondLargest = -1

12 < 35 && 12 > -1

SecondLargest = 12

35 < 35 -> No

1 > 12 -> No

10 > 12 -> No

34 < 35 && 34 > 12

SecondLargest = 34

1 > 34 -> No

---------------------------------

Final Answer

34

====================================================
*/