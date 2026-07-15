#include <bits/stdc++.h>
using namespace std;

/*
====================================================
        LeetCode 35 - Search Insert Position
====================================================

Problem Statement
----------------------------------------------------
Given a sorted array of distinct integers and a
target value, return the index if the target is
found.

If the target is not found, return the index where
it should be inserted to keep the array sorted.

Example
----------------------------------------------------
Input:
nums = [1,3,5,6]
target = 5

Output:
2

Input:
nums = [1,3,5,6]
target = 2

Output:
1

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:
- Since the array is sorted, Binary Search can be
  used efficiently.
- If target is found, return its index.
- Otherwise, keep track of the first element that is
  greater than the target.
- That index becomes the correct insertion position.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize:
   low = 0
   high = n - 1
   index = n

2. Find middle element.

3. If nums[mid] == target:
      return mid.

4. If nums[mid] < target:
      Search in the right half.

5. Otherwise:
      Store current index.
      Search in the left half.

6. Return index.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
Instead of checking every element one by one,
Binary Search eliminates half of the search space
after every comparison.

This makes it much faster than Linear Search.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(1)

Average Case : O(log n)

Worst Case   : O(log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

Reason:
Only a few extra variables are used.

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search
Lower Bound
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        // Default insertion position is at the end
        int index = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Search in right half
            else if (nums[mid] < target) {
                low = mid + 1;
            }

            // Possible insertion position
            else {
                index = mid;
                high = mid - 1;
            }
        }

        return index;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Binary Search
LeetCode Problem : 35
Time Complexity  : O(log n)
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Lower Bound
✔ Search Space Reduction
*/