#include <bits/stdc++.h>
using namespace std;

/*
====================================================
            LeetCode 912 - Sort an Array
                  Bubble Sort
====================================================

Problem Statement
----------------------------------------------------
Given an integer array nums, sort the array in
ascending order and return the sorted array.

----------------------------------------------------
Approach
----------------------------------------------------
Bubble Sort

Idea:
- Compare adjacent elements.
- If the left element is greater than the right,
  swap them.
- After every pass, the largest element moves to
  its correct position at the end of the array.
- Repeat this process until the entire array
  becomes sorted.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Run n-1 passes over the array.
2. Compare every pair of adjacent elements.
3. Swap them if they are in the wrong order.
4. After each pass, the largest unsorted element
   reaches its correct position.
5. Continue until the array is completely sorted.

----------------------------------------------------
Why Bubble Sort?
----------------------------------------------------
Bubble Sort repeatedly pushes the largest element
towards the end of the array through adjacent swaps.

It is useful for:
✔ Understanding sorting fundamentals.
✔ Small datasets.
✔ Learning comparison-based sorting.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(n²)
Reason:
Without optimization (swap flag), all passes
are executed even if the array is already sorted.

Average Case : O(n²)
Reason:
Multiple comparisons and swaps are required.

Worst Case   : O(n²)
Reason:
Reverse sorted array requires maximum swaps.

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

Reason:
Sorting is performed in-place.
No extra array is used.

----------------------------------------------------
Pattern
----------------------------------------------------
Sorting
Bubble Sort
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Total n-1 passes
        for (int i = 0; i < n - 1; i++) {

            // Compare adjacent elements
            for (int j = 0; j < n - i - 1; j++) {

                // Swap if elements are in wrong order
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        return nums;
    }
};