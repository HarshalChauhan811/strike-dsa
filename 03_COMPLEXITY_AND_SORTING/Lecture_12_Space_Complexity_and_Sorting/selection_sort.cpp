#include <bits/stdc++.h>
using namespace std;

/*
====================================================
            LeetCode 912 - Sort an Array
                Selection Sort
====================================================

Problem Statement
----------------------------------------------------
Given an integer array nums, sort the array in
ascending order and return the sorted array.

Example
----------------------------------------------------
Input:
nums = [5,2,3,1]

Output:
[1,2,3,5]

----------------------------------------------------
Approach
----------------------------------------------------
Selection Sort

Idea:
- Divide the array into two parts:
  1. Sorted Part
  2. Unsorted Part

- In every iteration, find the smallest element
  from the unsorted part.

- Swap it with the first element of the
  unsorted part.

- Increase the sorted portion by one element.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Start from index 0.
2. Assume the current index contains the minimum.
3. Traverse the remaining array.
4. Find the actual minimum element.
5. Swap it with the current index.
6. Repeat until the array becomes sorted.

----------------------------------------------------
Why Selection Sort?
----------------------------------------------------
Selection Sort selects the minimum element in every
iteration and places it at its correct position.

It is useful for:
✔ Understanding sorting fundamentals.
✔ Small datasets.
✔ When minimizing the number of swaps is important.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(n²)

Reason:
Even if the array is already sorted,
Selection Sort still scans the remaining array.

Average Case : O(n²)

Reason:
Every iteration searches for the minimum element.

Worst Case   : O(n²)

Reason:
The complete unsorted portion is scanned every time.

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

Reason:
Sorting is performed in-place.
No extra memory is used.

----------------------------------------------------
Pattern
----------------------------------------------------
Sorting
Selection Sort
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Traverse the array
        for (int i = 0; i < n - 1; i++) {

            // Assume current index has minimum element
            int minIndex = i;

            // Find the actual minimum element
            for (int j = i + 1; j < n; j++) {

                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            // Place minimum element at correct position
            swap(nums[i], nums[minIndex]);
        }

        return nums;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Selection Sort
LeetCode Problem : 912 - Sort an Array
Time Complexity  : O(n²)
Space Complexity : O(1)
Stable           : No
In-Place         : Yes
Adaptive         : No
*/