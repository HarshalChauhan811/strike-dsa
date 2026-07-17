#include <bits/stdc++.h>
using namespace std;

// GFG : Cyclically Rotate an Array by One

/*
====================================================
Problem --> Cyclically Rotate an Array by One

Definition
Array ke sabhi elements ko ek position right
shift karna hai aur last element ko first
position par lana hai.

----------------------------------------------------
Example 1

Input
Array : [1, 2, 3, 4, 5]

Output
[5, 1, 2, 3, 4]

----------------------------------------------------
Example 2

Input
Array : [10, 20, 30]

Output
[30, 10, 20]

----------------------------------------------------
Example 3

Input
Array : [7]

Output
[7]

----------------------------------------------------
Approach

1. Last element ko save kar lo.
2. Right se left tak sabhi elements ko
   ek position shift karo.
3. Last element ko first index par rakh do.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    void rotate(vector<int> &arr) {

        int n = arr.size();

        // Last element save kar lo
        int last = arr[n - 1];

        // Right shift
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        // Saved element ko first par rakho
        arr[0] = last;
    }
};

/*
====================
Dry Run

Array : [1, 2, 3, 4, 5]

last = 5

Shift

i = 4 -> [1,2,3,4,4]
i = 3 -> [1,2,3,3,4]
i = 2 -> [1,2,2,3,4]
i = 1 -> [1,1,2,3,4]

Place last at first

[5,1,2,3,4]

Output

[5,1,2,3,4]

====================
*/