#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 1539. Kth Missing Positive Number
// Pattern    : Binary Search
// Difficulty : Easy
// Time       : O(log n)
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Given a sorted array of positive integers and an integer k,
return the kth missing positive number.

Examples
--------

Example 1
Input:
arr = [2,3,4,7,11]
k = 5

Output:
9

Explanation:
Missing numbers are:
1, 5, 6, 8, 9, ...

The 5th missing positive number is 9.


Example 2
Input:
arr = [1,2,3,4]
k = 2

Output:
6

Explanation:
Missing numbers are:
5, 6, ...

The 2nd missing positive number is 6.


Example 3
Input:
arr = [2]
k = 1

Output:
1

Explanation:
The first missing positive number is 1.


Example 4
Input:
arr = [5,6,7]
k = 3

Output:
3

Explanation:
Missing numbers are:
1, 2, 3, 4...

The 3rd missing positive number is 3.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Traverse the array from left to right.

At every index,
calculate how many positive numbers
are missing till that index.

Missing Numbers till index:

arr[i] - (i + 1)

If the missing count becomes greater
than or equal to k,
then the kth missing number lies
before the current element.

Otherwise,
the kth missing number lies after
the last element of the array.

Algorithm
---------
1. Traverse the array.
2. Calculate missing numbers till each index.
3. If missing >= k,
   return i + k.
4. If no such index exists,
   return n + k.

Brute Force Code
----------------

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        for (int i = 0; i < n; i++) {

            // Missing numbers till current index
            int totalMissing = arr[i] - (i + 1);

            // Kth missing number lies before arr[i]
            if (totalMissing >= k) {
                return i + k;
            }
        }

        // Kth missing number lies after the last element
        return n + k;
    }
};

Time Complexity
---------------
O(n)

Space Complexity
----------------
O(1)

Why Not This Approach?
----------------------
This solution scans the array only once,
so it is much better than checking every
positive number one by one.

However, it still takes O(n) time.

Since the missing count is monotonic,
Binary Search can reduce the time
complexity to O(log n).
*/


/*
==============================================================================
Optimal Approach (Binary Search)
==============================================================================

Idea
----
At every index,
the expected value should be:

Expected Value = index + 1

If the actual value is larger,
some numbers are missing before it.

Missing Numbers till index:

arr[mid] - (mid + 1)

We Binary Search for the first index
where

Missing Numbers >= k

Final Answer:

start + k

Algorithm
---------
1. Initialize start = 0 and end = n - 1.
2. Find the middle index.
3. Calculate missing numbers.
4. If missing < k,
   search on the right.
5. Otherwise,
   search on the left.
6. Return start + k.

Why Binary Search Works?
------------------------
The number of missing values
never decreases as we move forward.

This monotonic property
allows Binary Search
to eliminate half of the search space
after every comparison.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Missing numbers till mid
            int missing = arr[mid] - (mid + 1);

            // Search on the right
            if (missing < k) {

                start = mid + 1;
            }

            // Search on the left
            else {

                end = mid - 1;
            }
        }

        return start + k;
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
arr = [2,3,4,7,11]
k = 5

Initial

start = 0
end = 4

Iteration 1
-----------

mid = 2

arr[mid] = 4

Missing = 4 - (2 + 1)

Missing = 1

1 < 5

Search right.

start = 3

Iteration 2
-----------

start = 3
end = 4

mid = 3

arr[mid] = 7

Missing = 7 - (3 + 1)

Missing = 3

3 < 5

Search right.

start = 4

Iteration 3
-----------

start = 4
end = 4

mid = 4

arr[mid] = 11

Missing = 11 - (4 + 1)

Missing = 6

6 >= 5

Search left.

end = 3

Loop Ends

start = 4

Answer = start + k

= 4 + 5

= 9

==============================================================================
Key Takeaways
==============================================================================

• Expected value at index i is i + 1.
• Missing count till index i = arr[i] - (i + 1).
• Missing count is monotonic.
• Binary Search finds the first index where missing >= k.
• Final answer = start + k.

==============================================================================
Related Problems
==============================================================================

• LeetCode 35 - Search Insert Position
• LeetCode 34 - Find First and Last Position of Element
• LeetCode 540 - Single Element in a Sorted Array
• LeetCode 704 - Binary Search
*/