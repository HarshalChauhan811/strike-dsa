#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 153. Find Minimum in Rotated Sorted Array
// Pattern    : Binary Search (Rotated Sorted Array)
// Difficulty : Medium
// Time       : O(log n)
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
An array of unique integers is sorted in ascending order
and then rotated at an unknown pivot.

Return the minimum element in the rotated array.

The solution must run in O(log n) time.

Examples
--------

Example 1
Input:
nums = [3,4,5,1,2]

Output:
1

Explanation:
The array is rotated after 5.
1 is the smallest element.


Example 2
Input:
nums = [4,5,6,7,0,1,2]

Output:
0

Explanation:
0 is the minimum element.


Example 3
Input:
nums = [11,13,15,17]

Output:
11

Explanation:
The array is already sorted.
The first element is the minimum.


Example 4
Input:
nums = [2,1]

Output:
1

Explanation:
After rotation, 1 becomes the minimum.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Traverse the entire array and keep track of the
smallest element.

Algorithm
---------
1. Assume the first element is the minimum.
2. Traverse the array.
3. If a smaller element is found, update the minimum.
4. Return the minimum element.

Brute Force Code
----------------

class Solution {
public:
    int findMin(vector<int>& nums) {

        int minimum = nums[0];

        for (int num : nums) {
            minimum = min(minimum, num);
        }

        return minimum;
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
It checks every element even though the array
has a special sorted structure.

Binary Search can eliminate half of the
search space after every comparison.
*/

/*
==============================================================================
Optimal Approach (Binary Search)
==============================================================================

Idea
----
Compare the middle element with the last element.

If nums[mid] > nums[end],
the minimum must lie on the right side.

Otherwise,
the minimum is either at mid
or somewhere on the left.

Algorithm
---------
1. Initialize start = 0 and end = n - 1.
2. Find the middle index.
3. If nums[mid] > nums[end]:
      Move start = mid + 1.
4. Otherwise:
      Move end = mid.
5. When start == end,
   it points to the minimum element.

Why Binary Search Works?
------------------------
A rotated sorted array is divided into two
sorted halves.

The right sorted half always contains the
smallest element whenever nums[mid] > nums[end].

Using this property, we discard half of the
search space after every comparison.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            // Minimum lies on the right side
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            // Minimum is at mid or on the left side
            else {
                end = mid;
            }
        }

        return nums[start];
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

Initial:
start = 0
end = 6

Iteration 1
-----------
mid = 3

nums[mid] = 7
nums[end] = 2

7 > 2

Minimum lies on the right.

start = 4

Iteration 2
-----------
start = 4
end = 6

mid = 5

nums[mid] = 1
nums[end] = 2

1 < 2

Minimum is at mid or on the left.

end = 5

Iteration 3
-----------
start = 4
end = 5

mid = 4

nums[mid] = 0
nums[end] = 1

0 < 1

end = 4

Now:
start = end = 4

Return nums[4] = 0

==============================================================================
Key Takeaways
==============================================================================

• Rotated sorted array contains two sorted halves.
• Compare nums[mid] with nums[end].
• nums[mid] > nums[end] → Minimum is on the right.
• Otherwise, minimum is at mid or on the left.
• Always use while(start < end).
• This is a classic Rotated Sorted Array Binary Search problem.

==============================================================================
Related Problems
==============================================================================

• LeetCode 33  - Search in Rotated Sorted Array
• LeetCode 81  - Search in Rotated Sorted Array II
• LeetCode 154 - Find Minimum in Rotated Sorted Array II
• LeetCode 852 - Peak Index in a Mountain Array
*/