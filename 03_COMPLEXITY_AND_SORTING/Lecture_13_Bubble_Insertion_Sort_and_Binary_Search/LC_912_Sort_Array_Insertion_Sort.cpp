#include <bits/stdc++.h>
using namespace std;

/*
====================================================
            LeetCode 912 - Sort an Array
                 Insertion Sort
====================================================

Problem Statement
----------------------------------------------------
Given an integer array nums, sort the array in
ascending order and return the sorted array.

----------------------------------------------------
Approach
----------------------------------------------------
Insertion Sort

Idea:
- Assume the first element is already sorted.
- Pick the next element one by one.
- Insert it into its correct position in the
  already sorted part of the array.
- Keep shifting larger elements towards the right
  until the correct position is found.
- Once the correct position is reached,
  stop further comparisons.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Start from index 1.
2. Compare the current element with previous elements.
3. If previous element is greater, swap them.
4. Continue moving left until the correct position
   is found.
5. Repeat for every element.

----------------------------------------------------
Why Insertion Sort?
----------------------------------------------------
Insertion Sort builds the sorted array gradually.

At every iteration:
- Left side remains sorted.
- Right side remains unsorted.

It is efficient for:
✔ Small datasets
✔ Nearly sorted arrays

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(n)
Reason:
Array is already sorted.
Only one comparison is required for each element.

Average Case : O(n²)
Reason:
Elements need to shift partially.

Worst Case   : O(n²)
Reason:
Reverse sorted array.
Every element shifts to the beginning.

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
Insertion Sort
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Assume first element is already sorted
        for (int i = 1; i < n; i++) {

            // Insert current element into sorted part
            for (int j = i; j > 0; j--) {

                // Move current element towards left
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }

                // Correct position found
                else {
                    break;
                }
            }
        }

        return nums;
    }
};