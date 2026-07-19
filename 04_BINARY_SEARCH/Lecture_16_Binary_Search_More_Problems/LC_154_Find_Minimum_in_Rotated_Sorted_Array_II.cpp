#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 154. Find Minimum in Rotated Sorted Array II
// Pattern    : Modified Binary Search (Rotated Sorted Array)
// Difficulty : Hard
// Time       : O(log n) Average | O(n) Worst Case
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Suppose an array is sorted in ascending order and then rotated
at an unknown pivot.

The array may contain duplicate elements.

Return the minimum element in the array.

Examples
--------

Example 1
Input:
nums = [1,3,5]

Output:
1

Explanation:
The array is not rotated.
The first element is the minimum.


Example 2
Input:
nums = [2,2,2,0,1]

Output:
0

Explanation:
After rotation, 0 becomes the smallest element.


Example 3
Input:
nums = [3,3,1,3]

Output:
1

Explanation:
Even with duplicates, 1 is the minimum element.


Example 4
Input:
nums = [10,1,10,10,10]

Output:
1

Explanation:
Duplicate values make the search direction ambiguous.


Example 5
Input:
nums = [2,2,2,2,2]

Output:
2

Explanation:
All elements are the same.
Any element can be considered the minimum.
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
Although it correctly finds the minimum,
it checks every element.

Since the array has a sorted structure,
Binary Search can eliminate half of the
search space after every comparison.
*/

/*
==============================================================================
Optimal Approach (Modified Binary Search)
==============================================================================

Idea
----
Compare nums[mid] with nums[end].

Case 1:
nums[mid] > nums[end]

The minimum must lie on the right side.

Move:
start = mid + 1

----------------------------------------------------

Case 2:
nums[mid] < nums[end]

The minimum is either at mid
or somewhere on the left.

Move:
end = mid

----------------------------------------------------

Case 3:
nums[mid] == nums[end]

We cannot determine which side
contains the minimum because
both values are equal.

Safely remove one duplicate.

Move:
end--

Algorithm
---------
1. Initialize start = 0 and end = n - 1.
2. Find the middle index.
3. Compare nums[mid] with nums[end].
4. Update the search space.
5. When start == end,
   it points to the minimum element.

Why Modified Binary Search Works?
---------------------------------
Normally, comparing nums[mid]
with nums[end] tells us which
half contains the minimum.

Duplicates create ambiguity.

Removing one duplicate does not
remove the minimum element,
so the algorithm remains correct.
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
            else if (nums[mid] < nums[end]) {

                end = mid;
            }

            // Duplicate values
            else {

                end--;
            }
        }

        return nums[start];
    }
};

/*
==============================================================================
Complexity Analysis
==============================================================================

Best Case
---------
O(1)

Average Case
------------
O(log n)

Worst Case
-----------
O(n)

Reason:
If many duplicate elements exist,
we may remove only one element
in each iteration.

Space Complexity
----------------
O(1)

==============================================================================
Dry Run
==============================================================================

Input:
nums = [2,2,2,0,1]

Initial

start = 0
end = 4

Iteration 1
-----------

mid = 2

nums[mid] = 2
nums[end] = 1

2 > 1

Minimum lies on the right.

start = 3

Iteration 2
-----------

start = 3
end = 4

mid = 3

nums[mid] = 0
nums[end] = 1

0 < 1

Minimum is at mid
or on the left.

end = 3

Now

start = end = 3

Return nums[3] = 0

==============================================================================
Special Case (Duplicates)
==============================================================================

Input:
nums = [10,1,10,10,10]

mid = 2

nums[mid] = 10
nums[end] = 10

Both are equal.

We cannot decide the correct side.

Safely remove one duplicate.

end--

Continue Binary Search.

Eventually,
minimum = 1

==============================================================================
Key Takeaways
==============================================================================

• Compare nums[mid] with nums[end].
• nums[mid] > nums[end] → Search right.
• nums[mid] < nums[end] → Search left including mid.
• nums[mid] == nums[end] → Remove one duplicate.
• Duplicates can degrade Binary Search to O(n).
• This is the duplicate version of LC 153.

==============================================================================
Related Problems
==============================================================================

• LeetCode 33  - Search in Rotated Sorted Array
• LeetCode 81  - Search in Rotated Sorted Array II
• LeetCode 153 - Find Minimum in Rotated Sorted Array
• LeetCode 852 - Peak Index in a Mountain Array
*/