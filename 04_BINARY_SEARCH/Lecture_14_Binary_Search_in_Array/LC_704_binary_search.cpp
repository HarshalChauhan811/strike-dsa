#include <bits/stdc++.h>
using namespace std;
/*
====================================================
             LeetCode 704 - Binary Search
====================================================

Problem
----------------------------------------------------
Given a sorted (ascending) integer array `nums` and
an integer `target`, return the index of `target`
if it exists. Otherwise, return -1.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : nums = [-1,0,3,5,9,12], target = 9
Output: 4

Example 2
Input : nums = [-1,0,3,5,9,12], target = 2
Output: -1

Example 3 (Edge Case)
Input : nums = [5], target = 5
Output: 0

----------------------------------------------------
Approach
----------------------------------------------------
1. Initialize two pointers:
      low = 0
      high = n - 1

2. Find the middle index:
      mid = low + (high - low) / 2

3. Compare nums[mid] with target:
      • nums[mid] == target → Return mid
      • nums[mid] < target  → Search Right Half
      • nums[mid] > target  → Search Left Half

4. Repeat until low > high.

----------------------------------------------------
Algorithm
----------------------------------------------------
• Start with the complete search space.
• Find the middle element.
• Discard the half where the target cannot exist.
• Continue until the target is found or the search
  space becomes empty.

----------------------------------------------------
Why use:
mid = low + (high - low) / 2 ?
----------------------------------------------------
Using

(low + high) / 2

may cause Integer Overflow when low and high are
very large.

Using

low + (high - low) / 2

avoids this problem.

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

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search

====================================================
                        CODE
====================================================
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            // Calculate middle index safely
            int mid = low + (high - low) / 2;

            // Target Found
            if (nums[mid] == target)
                return mid;

            // Search Right Half
            if (nums[mid] < target)
                low = mid + 1;

            // Search Left Half
            else
                high = mid - 1;
        }

        // Target Not Found
        return -1;
    }
};

/*
====================================================
                  SHORT DRY RUN
====================================================

Input:
nums   = [-1,0,3,5,9,12]
target = 9

----------------------------------------------------
Iteration 1

low  = 0
high = 5

mid = 2

nums[mid] = 3

3 < 9

Move Right Half

low  = 3
high = 5

----------------------------------------------------
Iteration 2

mid = 4

nums[mid] = 9

Target Found ✔

Return 4

====================================================
*/