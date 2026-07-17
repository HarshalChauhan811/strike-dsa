#include <bits/stdc++.h>
using namespace std;

/*
==========================================
GFG - Search an Element in an Array
==========================================

Problem Statement
------------------------------------------
Given an array arr[] and an integer target,
return the index of target if it exists.
Otherwise, return -1.

Example

Input:
arr = [1,2,3,4,5]
target = 4

Output:
3

Reason:
Target 4 index 3 par present hai.

------------------------------------------
Approach
------------------------------------------
• Array ko starting se end tak traverse karo.
• Har element ko target se compare karo.
• Match milte hi uska index return kar do.
• Agar poora array traverse ho jaye aur target na mile,
  to -1 return kar do.

Algorithm
------------------------------------------
1. Loop chalao 0 se n-1 tak.
2. Har element ko target se compare karo.
3. Agar equal ho to index return karo.
4. Agar target na mile to -1 return karo.

Time Complexity : O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    int search(int arr[], int n, int target) {

        // Array ke saare elements traverse karo
        for (int i = 0; i < n; i++) {

            // Target mil gaya
            if (arr[i] == target)
                return i;
        }

        // Target nahi mila
        return -1;
    }
};

/*
------------------------------------------
Summary
------------------------------------------
Algorithm        : Linear Search

Time Complexity  : O(n)

Space Complexity : O(1)

Concepts Used:
✔ Array Traversal
✔ Linear Search
*/