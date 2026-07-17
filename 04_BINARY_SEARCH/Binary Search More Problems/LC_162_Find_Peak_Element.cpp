#include <bits/stdc++.h>
using namespace std;

/*
====================================================
          LeetCode 162 - Find Peak Element
====================================================

Problem Statement
----------------------------------------------------
A peak element is an element that is strictly
greater than its adjacent neighbors.

Given an integer array nums, return the index of
any peak element.

You may assume that:

nums[-1] = -∞
nums[n]  = -∞

The solution must run in O(log n) time.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
nums = [1,2,3,1]

Output:
2

Reason:
3 is greater than both its neighbors.

----------------------------------------------------

Example 2

Input:
nums = [1,2,1,3,5,6,4]

Output:
5

Reason:
6 is greater than both its neighbors.
(Index 1 is also a valid peak.)

----------------------------------------------------

Example 3

Input:
nums = [1]

Output:
0

Reason:
A single element is always a peak.

----------------------------------------------------

Example 4

Input:
nums = [5,4,3,2,1]

Output:
0

Reason:
The first element is greater than
its only neighbor.

----------------------------------------------------

Example 5

Input:
nums = [1,2,3,4,5]

Output:
4

Reason:
The last element is greater than
its only neighbor.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:
- Compare the middle element with its next element.
- If nums[mid] < nums[mid + 1],
  we are on an increasing slope,
  so the peak lies on the right.
- Otherwise,
  we are on a decreasing slope
  or already at the peak,
  so search on the left including mid.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize:
   start = 0
   end = n - 1

2. Find the middle index.

3. If nums[mid] < nums[mid + 1]:
      - Move to the right half.

4. Otherwise:
      - Peak is at mid or on the left.
      - Move to the left half.

5. When start == end,
   it points to a peak element.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
A peak always exists because:

nums[-1] = -∞
nums[n]  = -∞

By checking the slope at mid,
we can eliminate half of the search space
after every comparison.

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
Peak Search
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            // Peak lies on the right side
            if (nums[mid] < nums[mid + 1]) {

                start = mid + 1;
            }
            else {

                // Peak is at mid or on the left side
                end = mid;
            }
        }

        return start;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Binary Search
LeetCode Problem : 162 - Find Peak Element

Time Complexity  : O(log n)
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Peak Search
✔ Search Space Reduction
✔ Increasing & Decreasing Slope
*/