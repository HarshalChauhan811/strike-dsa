#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 69. Sqrt(x)
// Pattern    : Binary Search (Answer Search)
// Difficulty : Easy
// Time       : O(log x)
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Given a non-negative integer x, return the integer square root of x.

The integer square root is the largest integer whose square is less
than or equal to x.

You must not use any built-in exponent function or operator.

Examples
--------

Example 1
Input:
x = 4

Output:
2

Explanation:
2 × 2 = 4


Example 2
Input:
x = 8

Output:
2

Explanation:
√8 = 2.828...
Floor value = 2.


Example 3
Input:
x = 15

Output:
3

Explanation:
√15 = 3.872...
Floor value = 3.
*/

/*
Brute Force
-----------

Idea:
Check every number starting from 0 until its square becomes
greater than x.

The previous number whose square was less than or equal to x
is the required answer.

Time Complexity : O(√x)
Space Complexity: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        long long i = 1;

        while (i * i <= x) {
            i++;
        }

        return i - 1;
    }
};

/*
Why Not Brute Force?
--------------------
For large values of x, checking every possible number becomes
unnecessarily slow. We can do much better using Binary Search.
*/

/*
Optimal Approach (Binary Search)
--------------------------------

Idea:
The answer always lies between 0 and x.

1. Find the middle element.
2. If mid² <= x, store mid as a possible answer.
3. Search on the right to find a larger valid answer.
4. Otherwise, search on the left.
5. Continue until the search space becomes empty.

Why Binary Search Works?
------------------------
As the value of mid increases, mid² also increases.

This monotonic property makes the search space sorted,
allowing us to eliminate half of the remaining elements
after every comparison.
*/

class Solution {
public:
    int mySqrt(int x) {

        int start = 0;
        int end = x;
        int answer = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Mid can be the answer
            if ((long long)mid * mid <= x) {

                answer = mid;

                // Try to find a larger valid answer
                start = mid + 1;
            }
            else {

                // Search in the left half
                end = mid - 1;
            }
        }

        return answer;
    }
};

/*
Complexity Analysis
-------------------
Time Complexity  : O(log x)
Space Complexity : O(1)

Dry Run
-------

Input:
x = 8

start = 0, end = 8

mid = 4
4² = 16 > 8
end = 3

mid = 1
1² = 1 <= 8
answer = 1
start = 2

mid = 2
2² = 4 <= 8
answer = 2
start = 3

mid = 3
3² = 9 > 8
end = 2

Loop ends.

Return 2

Key Takeaways
-------------
• Binary Search is used on the answer space.
• Store every valid answer before searching further.
• Move right to maximize the answer.
• Use long long to prevent integer overflow.
• This is a classic "Answer Search" Binary Search problem.
*/