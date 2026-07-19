#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 33. Search in Rotated Sorted Array
// Pattern    : Modified Binary Search (Rotated Sorted Array)
// Difficulty : Medium
// Time       : O(log n)
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
An integer array is sorted in ascending order and then
rotated at an unknown pivot.

Given the rotated array and a target value,
return the index of the target.

If the target is not present,
return -1.

Examples
--------

Example 1
Input:
nums = [4,5,6,7,0,1,2]
target = 0

Output:
4

Explanation:
Target 0 is present at index 4.


Example 2
Input:
nums = [4,5,6,7,0,1,2]
target = 3

Output:
-1

Explanation:
Target does not exist.


Example 3
Input:
nums = [1]
target = 0

Output:
-1

Explanation:
Only one element exists
and it is not the target.


Example 4
Input:
nums = [6,7,8,1,2,3,4,5]
target = 3

Output:
5

Explanation:
Target is present in the sorted right half.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Traverse the array one by one.

If the current element matches the target,
return its index.

Otherwise continue searching.

Algorithm
---------
1. Traverse the array.
2. Compare every element with target.
3. If found, return its index.
4. Otherwise return -1.

Brute Force Code
----------------

class Solution {
public:
    int search(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};

Time Complexity
---------------
O(n)

Space Complexity
----------------
O(1)

Why Not Brute Force?
--------------------
It checks every element.

Since the array is rotated but still
contains sorted parts,
Binary Search can eliminate half
of the search space after every comparison.
*/

/*
==============================================================================
Optimal Approach (Modified Binary Search)
==============================================================================

Idea
----
In every iteration,
at least one half of the array
is always sorted.

Identify the sorted half.

If the target belongs to that half,
continue searching there.

Otherwise search in the other half.

Algorithm
---------
1. Find the middle index.
2. If nums[mid] == target,
   return mid.
3. Check which half is sorted.
4. If target belongs to the sorted half,
   search there.
5. Otherwise,
   search in the other half.
6. Continue until target is found.

Why Modified Binary Search Works?
---------------------------------
Even after rotation,
one half of every search space
always remains sorted.

Using this property,
we can decide which half
may contain the target.

Therefore,
half of the search space
is discarded after every comparison.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[start] <= nums[mid]) {

                // Target lies in the left half
                if (nums[start] <= target && target < nums[mid]) {

                    end = mid - 1;
                }
                else {

                    start = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in the right half
                if (nums[mid] < target && target <= nums[end]) {

                    start = mid + 1;
                }
                else {

                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

/*
==============================================================================
Complexity Analysis
==============================================================================

Time Complexity
---------------
O(log n)

Space Complexity
----------------
O(1)

==============================================================================
Dry Run
==============================================================================

Input:
nums = [4,5,6,7,0,1,2]
target = 0

Initial

start = 0
end = 6

Iteration 1
-----------

mid = 3

nums[mid] = 7

Left half is sorted.

Target is not inside.

Move right.

start = 4

Iteration 2
-----------

start = 4
end = 6

mid = 5

nums[mid] = 1

Left half is sorted.

Target belongs to left half.

end = 4

Iteration 3
-----------

start = 4
end = 4

mid = 4

nums[mid] = 0

Target found.

Return 4

==============================================================================
Key Takeaways
==============================================================================

• One half is always sorted.
• Identify the sorted half first.
• Check whether the target belongs to that half.
• Discard the other half.
• Binary Search works because one side always remains sorted.
• Classic Rotated Sorted Array problem.

==============================================================================
Related Problems
==============================================================================

• LeetCode 81  - Search in Rotated Sorted Array II
• LeetCode 153 - Find Minimum in Rotated Sorted Array
• LeetCode 154 - Find Minimum in Rotated Sorted Array II
• LeetCode 852 - Peak Index in a Mountain Array
*/