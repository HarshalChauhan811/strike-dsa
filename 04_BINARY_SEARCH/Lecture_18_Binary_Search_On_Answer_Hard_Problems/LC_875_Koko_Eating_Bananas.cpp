#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 875. Koko Eating Bananas
// Pattern    : Binary Search on Answer
// Difficulty : Medium
// Time       : O(n × log(MaxPile))
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Koko loves eating bananas.

There are several piles of bananas.

The ith pile contains piles[i] bananas.

Koko chooses an eating speed k
(bananas per hour).

Every hour:
• She chooses one pile.
• She eats at most k bananas from that pile.
• If the pile contains fewer than k bananas,
  she finishes the pile and waits for the next hour.

Return the minimum eating speed
so that Koko can finish all bananas
within h hours.

Examples
--------

Example 1

Input:
piles = [3,6,7,11]
h = 8

Output:
4

Explanation:

Speed = 4

3  -> 1 hour
6  -> 2 hours
7  -> 2 hours
11 -> 3 hours

Total = 8 hours


Example 2

Input:
piles = [30,11,23,4,20]
h = 5

Output:
30

Explanation:
Each pile must be finished
within one hour.

Therefore,
the minimum speed is 30.


Example 3

Input:
piles = [30,11,23,4,20]
h = 6

Output:
23

Explanation:
At speed 23,
Koko finishes all bananas
in exactly 6 hours.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Try every possible eating speed.

The minimum speed starts from 1.

The maximum speed is the size
of the largest pile.

For every speed,
calculate the total hours required.

The first valid speed is the answer.

Algorithm
---------
1. Find the largest pile.
2. Try every speed from 1 to largest pile.
3. Calculate required hours.
4. If hours <= h,
   return the current speed.

Time Complexity
---------------
O(n × MaxPile)

Space Complexity
----------------
O(1)

Why Not Brute Force?
--------------------
The search space can be very large.

Trying every possible speed
is inefficient.

Binary Search reduces the
number of candidate speeds
significantly.
*/

/*
==============================================================================
Optimal Approach (Binary Search on Answer)
==============================================================================

Idea
----
We are NOT searching for a pile.

We are searching for the minimum
eating speed.

Suppose Koko eats k bananas per hour.

Can she finish all bananas
within h hours?

If YES,
try a smaller speed.

If NO,
increase the speed.

Search Space
------------

Minimum Answer
1 banana/hour

Maximum Answer
Largest pile

Algorithm
---------
1. start = 1.
2. end = Largest pile.
3. Find mid.
4. Calculate required hours.
5. If possible:
      Save answer.
      Search left.
6. Otherwise:
      Search right.

Why Binary Search Works?
------------------------
As the eating speed increases,

the required hours decrease.

Speed ↑

Hours ↓

This forms a monotonic property.

Binary Search efficiently finds
the minimum valid speed.
*/

class Solution {
public:

    // Check if Koko can finish all bananas
    // within h hours at the given speed
    bool possible(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for (int bananas : piles) {

            // Ceiling Division
            hours += (bananas + speed - 1) / speed;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Speed is sufficient
            if (possible(piles, h, mid)) {

                answer = mid;
                end = mid - 1;
            }

            // Increase the speed
            else {

                start = mid + 1;
            }
        }

        return answer;
    }
};

/*
==============================================================================
Complexity Analysis
==============================================================================

possible()
----------
O(n)

Binary Search
-------------
O(log(MaxPile))

Overall Time Complexity
-----------------------
O(n × log(MaxPile))

Space Complexity
----------------
O(1)

==============================================================================
Dry Run
==============================================================================

Input

piles = [3,6,7,11]

h = 8

Search Space

start = 1

end = 11

Iteration 1
-----------

mid = 6

Hours Required

3  -> 1

6  -> 1

7  -> 2

11 -> 2

Total = 6

Possible

answer = 6

Search Left

Iteration 2
-----------

mid = 3

Hours Required

3  -> 1

6  -> 2

7  -> 3

11 -> 4

Total = 10

Not Possible

Search Right

Iteration 3
-----------

mid = 4

Hours Required

3  -> 1

6  -> 2

7  -> 2

11 -> 3

Total = 8

Possible

answer = 4

Search Left

Loop Ends

Final Answer

4

==============================================================================
Key Takeaways
==============================================================================

• This is a Binary Search on Answer problem.
• Minimum answer = 1 banana/hour.
• Maximum answer = Largest pile.
• Ceiling Division calculates hours for each pile.
• Binary Search finds the minimum valid speed.
• Speed and required hours form a monotonic relationship.

==============================================================================
Related Problems
==============================================================================

• LeetCode 1011 - Capacity To Ship Packages Within D Days
• LeetCode 410 - Split Array Largest Sum
• GFG - Allocate Minimum Number of Pages
• GFG - Painter's Partition Problem
*/