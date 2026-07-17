#include <bits/stdc++.h>
using namespace std;

/*
==========================================
GFG - Check if Array is Sorted
==========================================

Problem Statement
------------------------------------------
Given an array arr[],
check whether it is sorted
in non-decreasing order.

Return true if sorted,
otherwise return false.

------------------------------------------
Examples
------------------------------------------

Example 1

Input:
arr = [1,2,3,4,5]

Output:
true

Reason:
Har next element previous element
se bada ya equal hai.

--------------------------

Example 2

Input:
arr = [1,2,2,3,5]

Output:
true

Reason:
Equal elements allowed hain,
isliye array sorted hai.

--------------------------

Example 3

Input:
arr = [5,4,3,2,1]

Output:
false

Reason:
4 < 5
Order first comparison par hi
break ho gaya.

--------------------------

Example 4

Input:
arr = [10]

Output:
true

Reason:
Single element array
hamesha sorted hoti hai.

------------------------------------------
Approach
------------------------------------------
• Har current element ko previous element se compare karo.
• Agar current element previous se chhota mil jaye,
  to array sorted nahi hai.
• Agar poora loop complete ho jaye,
  to array sorted hai.

Algorithm
------------------------------------------
1. Loop 1 se n-1 tak chalao.
2. Har element ko previous se compare karo.
3. Agar arr[i] < arr[i-1], return false.
4. Loop complete ho jaye, return true.

Time Complexity : O(n)

Space Complexity: O(1)
*/

class Solution {
public:

    bool arraySortedOrNot(int arr[], int n) {

        // First element ka koi previous nahi hota.
        for (int i = 1; i < n; i++) {

            // Order break ho gaya.
            if (arr[i] < arr[i - 1])
                return false;
        }

        // Array sorted hai.
        return true;
    }
};

/*
------------------------------------------
Summary
------------------------------------------
Algorithm        : Linear Traversal

Time Complexity  : O(n)

Space Complexity : O(1)

Concepts Used:
✔ Array Traversal
✔ Comparison
✔ Sorted Array Check
*/