#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 1011. Capacity To Ship Packages Within D Days
// Pattern    : Binary Search on Answer
// Difficulty : Medium
// Time       : O(n × log(sum))
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
A conveyor belt has packages that must be shipped.

The ith package has weights[i] weight.

Packages must be shipped in the given order.

Every day:
• Load packages one by one.
• The total weight loaded must not exceed the ship's capacity.

Return the minimum ship capacity required to ship
all packages within the given number of days.

Examples
--------

Example 1

Input:
weights = [1,2,3,4,5,6,7,8,9,10]
days = 5

Output:
15

Explanation:

Day 1:
1 + 2 + 3 + 4 + 5 = 15

Day 2:
6 + 7 = 13

Day 3:
8

Day 4:
9

Day 5:
10

Minimum required capacity = 15


Example 2

Input:
weights = [3,2,2,4,1,4]
days = 3

Output:
6

Explanation:

Day 1:
3 + 2 = 5

Day 2:
2 + 4 = 6

Day 3:
1 + 4 = 5


Example 3

Input:
weights = [1,2,3,1,1]
days = 4

Output:
3

Explanation:
Capacity 3 is enough to ship all packages
within 4 days.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Try every possible ship capacity.

The minimum capacity starts from the
largest package.

The maximum capacity is the sum of
all package weights.

For every capacity,
check whether all packages can be
shipped within the given number of days.

The first valid capacity is the answer.

Algorithm
---------
1. Find the largest package.
2. Find the total weight.
3. Try every capacity from largest weight to total weight.
4. Check whether shipping is possible.
5. Return the first valid capacity.

Time Complexity
---------------
O(n × sum)

Space Complexity
----------------
O(1)

Why Not Brute Force?
--------------------
The search space can be very large.

Checking every possible capacity
is inefficient.

Binary Search reduces the number
of possible answers significantly.
*/

/*
==============================================================================
Optimal Approach (Binary Search on Answer)
==============================================================================

Idea
----
We are NOT searching for a package.

We are searching for the minimum ship capacity.

Suppose the ship capacity is X.

Can all packages be shipped
within the given days?

If YES,
try a smaller capacity.

If NO,
increase the capacity.

Search Space
------------

Minimum Answer
Largest Package Weight

Maximum Answer
Sum of All Package Weights

Algorithm
---------
1. start = Maximum weight.
2. end = Sum of all weights.
3. Find mid.
4. Check whether shipping is possible.
5. If possible:
      Save answer.
      Search left.
6. Otherwise:
      Search right.

Why Binary Search Works?
------------------------
As the ship capacity increases,

the required number of days
never increases.

Capacity ↑

Required Days ↓

This is a monotonic property.

Binary Search efficiently finds
the minimum valid capacity.
*/

class Solution {
public:

    // Check if all packages can be shipped
    // within the given capacity
    bool possible(vector<int>& weights, int days, int capacity) {

        int currentWeight = 0;
        int requiredDays = 1;

        for (int weight : weights) {

            // Load into the current day
            if (currentWeight + weight <= capacity) {

                currentWeight += weight;
            }

            // Start a new day
            else {

                requiredDays++;
                currentWeight = weight;
            }
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Capacity works
            if (possible(weights, days, mid)) {

                answer = mid;
                end = mid - 1;
            }

            // Increase capacity
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
O(log(sum))

Overall Time Complexity
-----------------------
O(n × log(sum))

Space Complexity
----------------
O(1)

==============================================================================
Dry Run
==============================================================================

Input

weights = [3,2,2,4,1,4]

days = 3

Search Space

start = 4

end = 16

Iteration 1
-----------

mid = 10

Day 1:
3 + 2 + 2 = 7

Day 2:
4 + 1 + 4 = 9

Possible

answer = 10

Search Left

Iteration 2
-----------

mid = 6

Day 1:
3 + 2 = 5

Day 2:
2 + 4 = 6

Day 3:
1 + 4 = 5

Possible

answer = 6

Search Left

Iteration 3
-----------

mid = 4

Need more than 3 days

Not Possible

Search Right

Iteration 4
-----------

mid = 5

Need more than 3 days

Not Possible

Search Right

Loop Ends

Final Answer

6

==============================================================================
Key Takeaways
==============================================================================

• This is a Binary Search on Answer problem.
• Minimum answer = Largest package weight.
• Maximum answer = Sum of all package weights.
• Greedy simulation checks whether a capacity is valid.
• Binary Search finds the smallest valid capacity.
• Capacity and required days form a monotonic relationship.

==============================================================================
Related Problems
==============================================================================

• GFG - Allocate Minimum Number of Pages
• GFG - Painter's Partition Problem
• LeetCode 410 - Split Array Largest Sum
• GFG - Aggressive Cows
*/