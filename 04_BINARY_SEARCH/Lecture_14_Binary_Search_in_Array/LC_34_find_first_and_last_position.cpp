#include <bits/stdc++.h>
using namespace std;

/*
====================================================
      LeetCode 34 - Find First and Last Position
            of Element in Sorted Array
====================================================

Problem Statement
----------------------------------------------------
Given a sorted array of integers nums and a target
value, return the first and last position of the
target in the array.

If the target is not present, return [-1, -1].

Example
----------------------------------------------------
Input:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:
- Perform Binary Search twice.
- First Binary Search finds the first occurrence.
- Second Binary Search finds the last occurrence.
- Whenever target is found:
    • Save the index.
    • Continue searching in the required direction.

First Occurrence:
- Move towards the left half.

Last Occurrence:
- Move towards the right half.

----------------------------------------------------
Algorithm
----------------------------------------------------
Step 1:
Run Binary Search to find the first occurrence.
If target is found:
    - Store the index.
    - Continue searching on the left.

Step 2:
Run Binary Search again to find the last occurrence.
If target is found:
    - Store the index.
    - Continue searching on the right.

Step 3:
Return {first, last}.

----------------------------------------------------
Why Two Binary Searches?
----------------------------------------------------
Binary Search normally stops after finding
the target.

Here, we need:
✔ Leftmost occurrence.
✔ Rightmost occurrence.

Therefore, we perform Binary Search twice.

----------------------------------------------------
Time Complexity
----------------------------------------------------
First Binary Search  : O(log n)

Second Binary Search : O(log n)

Total Time           : O(log n)

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
First Occurrence
Last Occurrence
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = -1;
        int last = -1;

        // -------------------------------
        // Find First Occurrence
        // -------------------------------
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                first = mid;

                // Search towards left
                high = mid - 1;
            }
            else if (nums[mid] < target) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        // -------------------------------
        // Find Last Occurrence
        // -------------------------------
        low = 0;
        high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                last = mid;

                // Search towards right
                low = mid + 1;
            }
            else if (nums[mid] < target) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        return {first, last};
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Binary Search
LeetCode Problem : 34
Time Complexity  : O(log n)
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ First Occurrence
✔ Last Occurrence
✔ Search Space Reduction
*/