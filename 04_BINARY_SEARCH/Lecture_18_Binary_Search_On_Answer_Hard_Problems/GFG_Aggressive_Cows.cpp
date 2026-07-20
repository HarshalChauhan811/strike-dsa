#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// GFG / SPOJ - Aggressive Cows
// Pattern    : Binary Search on Answer
// Difficulty : Hard
// Time       : O(n log n + n log(MaxDistance))
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Given the positions of stalls and the number of cows.

Place all cows in the stalls such that
the minimum distance between any two cows
is as large as possible.

Return the largest possible minimum distance.

Examples
--------

Example 1

Input:
stalls = [1,2,4,8,9]
cows = 3

Output:
3

Explanation:

Cow 1 -> Stall 1

Cow 2 -> Stall 4

Cow 3 -> Stall 8

Minimum Distance = 3


Example 2

Input:
stalls = [1,2,3,4,5]
cows = 3

Output:
2

Explanation:

Cow 1 -> Stall 1

Cow 2 -> Stall 3

Cow 3 -> Stall 5

Minimum Distance = 2


Example 3

Input:
stalls = [1,4,7,10]
cows = 2

Output:
9

Explanation:

Place cows at stalls 1 and 10.

Minimum Distance = 9
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Try every possible minimum distance.

The minimum distance starts from 1.

The maximum distance is the difference
between the last and first stall.

For every distance,
check whether all cows can be placed.

The largest valid distance is the answer.

Algorithm
---------
1. Sort the stalls.
2. Find the maximum possible distance.
3. Try every distance from 1 to maximum distance.
4. Check if all cows can be placed.
5. Store the largest valid distance.

Time Complexity
---------------
O(n × MaxDistance)

Space Complexity
----------------
O(1)

Why Not Brute Force?
--------------------
The distance range can be very large.

Trying every possible distance
is inefficient.

Binary Search significantly
reduces the number of checks.
*/

/*
==============================================================================
Optimal Approach (Binary Search on Answer)
==============================================================================

Idea
----
We are NOT searching for a stall.

We are searching for the maximum
minimum distance.

Suppose the minimum required distance is X.

Can all cows be placed
while maintaining at least X distance?

If YES,
try a larger distance.

If NO,
reduce the distance.

Search Space
------------

Minimum Answer
1

Maximum Answer
Last Stall - First Stall

Algorithm
---------
1. Sort the stalls.
2. start = 1.
3. end = Last Stall - First Stall.
4. Find mid.
5. Check if placement is possible.
6. If possible:
      Save answer.
      Search right.
7. Otherwise:
      Search left.

Why Binary Search Works?
------------------------
As the required minimum distance increases,

placing cows becomes harder.

Distance ↑

Placement Difficulty ↑

Possible → Possible → Impossible → Impossible

This monotonic property
allows Binary Search to find
the largest valid distance efficiently.
*/

class Solution {
public:

    // Check if all cows can be placed
    // with at least the given minimum distance
    bool possible(vector<int>& stalls, int cows, int distance) {

        int placed = 1;
        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {

            // Place the next cow
            if (stalls[i] - lastPosition >= distance) {

                placed++;
                lastPosition = stalls[i];
            }
        }

        return placed >= cows;
    }

    int aggressiveCows(vector<int>& stalls, int cows) {

        sort(stalls.begin(), stalls.end());

        int start = 1;
        int end = stalls.back() - stalls.front();

        int answer = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Current distance works
            if (possible(stalls, cows, mid)) {

                answer = mid;
                start = mid + 1;
            }

            // Reduce the distance
            else {

                end = mid - 1;
            }
        }

        return answer;
    }
};

/*
==============================================================================
Complexity Analysis
==============================================================================

Sorting
-------
O(n log n)

possible()
----------
O(n)

Binary Search
-------------
O(log(MaxDistance))

Overall Time Complexity
-----------------------
O(n log n + n log(MaxDistance))

Space Complexity
----------------
O(1)

==============================================================================
Dry Run
==============================================================================

Input

stalls = [1,2,4,8,9]

cows = 3

After Sorting

[1,2,4,8,9]

Search Space

start = 1

end = 8

Iteration 1
-----------

mid = 4

Place cows

1

Next possible = 8

Only 2 cows placed

Not Possible

Search Left

Iteration 2
-----------

mid = 2

Place cows

1

4

8

3 cows placed

Possible

answer = 2

Search Right

Iteration 3
-----------

mid = 3

Place cows

1

4

8

3 cows placed

Possible

answer = 3

Search Right

Iteration 4
-----------

mid = 3

Search ends

Final Answer

3

==============================================================================
Key Takeaways
==============================================================================

• This is a Binary Search on Answer problem.
• Sort the stalls before applying Binary Search.
• Minimum answer = 1.
• Maximum answer = Last Stall − First Stall.
• Greedy placement checks whether a distance is valid.
• Binary Search finds the largest possible minimum distance.

==============================================================================
Related Problems
==============================================================================

• GFG - Allocate Minimum Number of Pages
• GFG - Painter's Partition Problem
• LeetCode 410 - Split Array Largest Sum
• LeetCode 1011 - Capacity To Ship Packages Within D Days
• LeetCode 875 - Koko Eating Bananas