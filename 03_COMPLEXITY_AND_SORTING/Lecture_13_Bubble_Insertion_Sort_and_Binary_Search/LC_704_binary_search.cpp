/*
====================================================
                LeetCode 704 - Binary Search
====================================================

Problem Statement
----------------------------------------------------
Given a sorted (ascending order) integer array `nums`
and an integer `target`, return the index of target
if it exists. Otherwise, return -1.

Example:
----------------------------------------------------
Input:
nums = [-1,0,3,5,9,12]
target = 9

Output:
4

----------------------------------------------------
Approach
----------------------------------------------------
Since the array is sorted, we can eliminate half of
the search space after every comparison.

Algorithm:
1. Initialize two pointers:
   - low = 0
   - high = n - 1

2. Find the middle index.
      mid = low + (high - low) / 2

3. Compare nums[mid] with target:
   - If equal → return mid.
   - If target is greater → search right half.
   - If target is smaller → search left half.

4. Repeat until low > high.

5. If target is not found, return -1.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
Instead of checking every element one by one,
Binary Search discards half of the array every step,
making it much faster.

Linear Search:
Time Complexity = O(n)

Binary Search:
Time Complexity = O(log n)

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case   : O(1)
Average Case: O(log n)
Worst Case  : O(log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search
*/

class Solution {
public:

    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            // Prevents integer overflow
            int mid = low + (high - low) / 2;

            // Target Found
            if (nums[mid] == target) {
                return mid;
            }

            // Search Right Half
            else if (nums[mid] < target) {
                low = mid + 1;
            }

            // Search Left Half
            else {
                high = mid - 1;
            }
        }

        // Target doesn't exist
        return -1;
    }
};