#include <bits/stdc++.h>
using namespace std;

/*
==========================================
GFG - Reverse an Array
==========================================

Problem Statement
------------------------------------------
Given an array arr[],
reverse the array in-place.

Example

Input:
arr = [1,2,3,4,5]

Output:
[5,4,3,2,1]

Reason:
First element last se,
second element second last se
swap hota hai.

------------------------------------------
Approach
------------------------------------------
• Opposite elements ko swap karte jao.
• Ek swap me 2 elements apni correct position par aa jate hain.
• Isliye sirf n/2 swaps hi required hote hain.

Algorithm
------------------------------------------
1. Loop 0 se n/2 tak chalao.
2. arr[i] aur arr[n-1-i] ko swap karo.
3. Array reverse ho jayega.

Time Complexity : O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    void reverseArray(int arr[], int n) {

        // Sirf half array tak swap karna hai.
        for (int i = 0; i < n / 2; i++) {

            // Opposite elements swap karo.
            int temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
    }
};

/*
------------------------------------------
Summary
------------------------------------------
Algorithm        : Two Pointer (Swapping)

Time Complexity  : O(n)

Space Complexity : O(1)

Concepts Used:
✔ Array
✔ Two Pointer
✔ In-place Swapping
*/