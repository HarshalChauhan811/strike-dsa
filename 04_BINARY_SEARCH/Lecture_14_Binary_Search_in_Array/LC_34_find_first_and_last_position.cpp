#include <bits/stdc++.h>
using namespace std;

/*
====================================================
      LeetCode 34 - Find First and Last Position
            of Element in Sorted Array
====================================================

Problem Statement
----------------------------------------------------
Given a sorted array of integers nums and a target,
return the first and last position of the target.

If the target is not present, return [-1, -1].

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]

Reason:
Target first appears at index 3
and last appears at index 4.

----------------------------------------------------

Example 2

Input:
nums = [5,7,7,8,8,10]
target = 6

Output:
[-1,-1]

Reason:
Target does not exist in the array.

----------------------------------------------------

Example 3

Input:
nums = []
target = 0

Output:
[-1,-1]

Reason:
The array is empty.

----------------------------------------------------

Example 4

Input:
nums = [2,2]
target = 2

Output:
[0,1]

Reason:
The target occupies the entire array.

----------------------------------------------------

Example 5

Input:
nums = [1]
target = 1

Output:
[0,0]

Reason:
Only one element exists,
and it matches the target.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:
- Perform Binary Search twice.
- First Binary Search finds the first occurrence.
- Second Binary Search finds the last occurrence.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Find the first occurrence.
2. Reset the search space.
3. Find the last occurrence.
4. Return both indices.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
The array is already sorted.

Binary Search reduces the search space by half
after every comparison, making it much faster
than Linear Search.

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

        vector<int> ans(2, -1);

        int start = 0;
        int end = nums.size() - 1;

        // Find First Occurrence
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {

                ans[0] = mid;      // Store possible answer
                end = mid - 1;     // Search on left side
            }
            else if (nums[mid] < target) {

                start = mid + 1;
            }
            else {

                end = mid - 1;
            }
        }

        // Reset search space
        start = 0;
        end = nums.size() - 1;

        // Find Last Occurrence
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {

                ans[1] = mid;      // Store possible answer
                start = mid + 1;   // Search on right side
            }
            else if (nums[mid] < target) {

                start = mid + 1;
            }
            else {

                end = mid - 1;
            }
        }

        return ans;
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
✔ Answer Search
*/