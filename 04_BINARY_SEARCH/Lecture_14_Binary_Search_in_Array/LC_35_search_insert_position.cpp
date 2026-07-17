#include <bits/stdc++.h>
using namespace std;

/*
====================================================
        LeetCode 35 - Search Insert Position
          (Lower Bound Implementation)
====================================================

Problem Statement
----------------------------------------------------
Given a sorted array of distinct integers and a
target value, return the index if the target is
found.

If the target is not found, return the index where
it should be inserted to maintain the sorted order.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
nums = [1,3,5,6]
target = 5

Output:
2

Reason:
Target exists at index 2.

----------------------------------------------------

Example 2

Input:
nums = [1,3,5,6]
target = 2

Output:
1

Reason:
2 should be inserted before 3.

----------------------------------------------------

Example 3

Input:
nums = [1,3,5,6]
target = 7

Output:
4

Reason:
Target is greater than every element,
so it will be inserted at the end.

----------------------------------------------------

Example 4

Input:
nums = [1,3,5,6]
target = 0

Output:
0

Reason:
Target is smaller than every element,
so it will be inserted at the beginning.

----------------------------------------------------

Example 5

Input:
nums = [1]
target = 1

Output:
0

Reason:
Target already exists in the array.

----------------------------------------------------
Approach
----------------------------------------------------
Lower Bound using Binary Search

Idea:
- Find the first element that is greater than or
  equal to the target.
- Store every possible answer.
- Continue searching on the left to find the
  earliest valid position.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize:
   start = 0
   end = n - 1
   answer = n

2. Find the middle element.

3. If nums[mid] >= target:
      - Store current index.
      - Search on the left.

4. Otherwise:
      - Search on the right.

5. Return answer.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
The array is already sorted.

Binary Search removes half of the search space
after every comparison.

The first element that is greater than or equal
to the target is called the Lower Bound.

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

        int start = 0;
        int end = nums.size() - 1;

        // Default insertion position
        int answer = nums.size();

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Possible answer found
            if (nums[mid] >= target) {

                answer = mid;

                // Search on the left
                end = mid - 1;
            }
            else {

                // Search on the right
                start = mid + 1;
            }
        }

        return answer;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Binary Search (Lower Bound)
LeetCode Problem : 35 - Search Insert Position

Time Complexity  : O(log n)
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Lower Bound
✔ Search Space Reduction
✔ Answer Search
*/