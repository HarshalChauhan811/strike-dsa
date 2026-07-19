#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 852. Peak Index in a Mountain Array
// Pattern    : Binary Search (Peak Element)
// Difficulty : Medium
// Time       : O(log n)
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
A mountain array is an array where:

1. Elements first strictly increase.
2. After reaching the peak, elements strictly decrease.

Return the index of the peak element.

Examples
--------

Example 1
Input:
arr = [0,1,0]

Output:
1

Explanation:
1 is the highest element.


Example 2
Input:
arr = [0,2,1,0]

Output:
1

Explanation:
2 is the peak element.


Example 3
Input:
arr = [0,10,5,2]

Output:
1

Explanation:
10 is the maximum element.


Example 4
Input:
arr = [3,5,3,2,0]

Output:
1

Explanation:
5 is the highest value in the array.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Traverse the entire array and keep track of the maximum element.

Since the peak element is always the maximum element in a mountain
array, its index will be the required answer.

Algorithm
---------
1. Assume the first element is the peak.
2. Traverse the array.
3. If a larger element is found, update the peak index.
4. Return the final peak index.

Brute Force Code
----------------

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int peakIndex = 0;

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] > arr[peakIndex]) {
                peakIndex = i;
            }
        }

        return peakIndex;
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
Although it correctly finds the answer, it checks every
element in the array.

Since the array is already a Mountain Array, we can use
Binary Search to eliminate half of the search space
after every comparison.
*/

/*
==============================================================================
Optimal Approach (Binary Search)
==============================================================================

Idea
----
Instead of searching every element, observe the slope.

If arr[mid] < arr[mid + 1],
we are on the increasing part,
so the peak must be on the right.

Otherwise,
we are on the decreasing part or already at the peak,
so keep mid and move left.

Algorithm
---------
1. Initialize start = 0 and end = n - 1.
2. Find the middle index.
3. Compare arr[mid] with arr[mid + 1].
4. If arr[mid] < arr[mid + 1]:
      Move start = mid + 1.
5. Otherwise:
      Move end = mid.
6. When start == end,
   it points to the peak index.

Why Binary Search Works?
------------------------
A mountain array has only one peak.

Increasing  --->  Peak  --->  Decreasing

By checking the slope around mid,
we can always determine which half contains the peak.

Therefore, half of the search space is discarded
after every comparison.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            // Peak lies on the right side
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            // Peak is at mid or on the left side
            else {
                end = mid;
            }
        }

        return start;
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
arr = [0,2,5,3,1]

Initial:
start = 0
end = 4

Iteration 1
-----------
mid = 2

arr[mid] = 5
arr[mid + 1] = 3

5 > 3

Peak is on the left (including mid)

end = 2

Iteration 2
-----------
start = 0
end = 2

mid = 1

arr[mid] = 2
arr[mid + 1] = 5

2 < 5

Peak is on the right

start = 2

Now:
start = end = 2

Return 2

==============================================================================
Key Takeaways
==============================================================================

• Mountain Array has exactly one peak.
• Compare arr[mid] with arr[mid + 1].
• Increasing slope → move right.
• Decreasing slope → keep mid and move left.
• Always use while(start < end).
• This is a classic Peak Element Binary Search problem.

==============================================================================
Related Problems
==============================================================================

• LeetCode 162 - Find Peak Element
• LeetCode 1095 - Find in Mountain Array
• LeetCode 153 - Find Minimum in Rotated Sorted Array
• LeetCode 154 - Find Minimum in Rotated Sorted Array II
*/