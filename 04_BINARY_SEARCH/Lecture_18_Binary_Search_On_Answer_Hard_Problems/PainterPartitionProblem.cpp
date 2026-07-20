#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// GFG - Painter's Partition Problem
// Pattern    : Binary Search on Answer
// Difficulty : Hard
// Time       : O(n × log(sum))
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Given an array boards[] where boards[i] represents
the length of the ith board and an integer painters
representing the number of painters.

Each painter can paint only contiguous boards.

A board cannot be divided between painters.

Find the minimum time required to paint all boards.

If allocation is not possible,
return -1.

Examples
--------

Example 1

Input:
boards = [5,10,30,20,15]
painters = 3

Output:
35

Explanation:

Painter 1:
5 + 10 + 20 = 35

Painter 2:
30

Painter 3:
15

Maximum time = 35


Example 2

Input:
boards = [10,20,30,40]
painters = 2

Output:
60

Explanation:

Painter 1:
10 + 20 + 30 = 60

Painter 2:
40

Maximum time = 60


Example 3

Input:
boards = [10,20]
painters = 3

Output:
-1

Explanation:
Every painter must paint at least one board.
There are fewer boards than painters.
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Try every possible value of the maximum
painting time.

For each value,
check whether all boards can be painted
using the given number of painters.

The first valid value is the answer.

Algorithm
---------
1. Find the largest board.
2. Find the total length of all boards.
3. Try every value from largest board to total sum.
4. Check if painting is possible.
5. Return the first valid answer.

Time Complexity
---------------
O(n × sum)

Space Complexity
----------------
O(1)

Why Not Brute Force?
--------------------
The search space can be very large.

Checking every possible answer
is inefficient.

Binary Search reduces the search
space significantly.
*/

/*
==============================================================================
Optimal Approach (Binary Search on Answer)
==============================================================================

Idea
----
We are NOT searching for a board.

We are searching for the minimum
maximum time required.

Suppose every painter is allowed
to paint at most X units.

Can all boards be painted?

If YES,
try a smaller answer.

If NO,
increase the allowed time.

Search Space
------------

Minimum Answer
Largest Board

Maximum Answer
Sum of All Boards

Algorithm
---------
1. If painters > boards,
   return -1.

2. low = largest board.

3. high = total sum of boards.

4. Find mid.

5. Check if painting is possible.

6. If possible:
      Save answer.
      Search left.

7. Otherwise:
      Search right.

Why Binary Search Works?
------------------------
As the maximum allowed time increases,

painting becomes easier.

This creates a monotonic property.

Impossible → Impossible → Possible → Possible

Binary Search finds the first
possible answer efficiently.
*/

class Solution {
public:

    // Check if all boards can be painted within the given limit
    bool canPaint(vector<int>& boards, int painters, int limit) {

        int painterCount = 1;
        int currentTime = 0;

        for (int board : boards) {

            // Current painter paints this board
            if (currentTime + board <= limit) {
                currentTime += board;
            }

            // Assign board to the next painter
            else {

                painterCount++;
                currentTime = board;
            }
        }

        return painterCount <= painters;
    }

    int minTime(vector<int>& boards, int painters) {

        // Allocation is impossible
        if (painters > boards.size())
            return -1;

        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0);

        int answer = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Painting is possible
            if (canPaint(boards, painters, mid)) {

                answer = mid;
                high = mid - 1;
            }

            // Increase the allowed time
            else {

                low = mid + 1;
            }
        }

        return answer;
    }
};

/*
==============================================================================
Complexity Analysis
==============================================================================

canPaint()
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

boards = [10,20,30,40]

painters = 2

Search Space

low = 40

high = 100

Iteration 1
-----------

mid = 70

Painter 1

10 + 20 + 30 = 60

Painter 2

40

Possible

answer = 70

Search Left

Iteration 2
-----------

mid = 54

Need 3 painters

Not Possible

Search Right

Iteration 3
-----------

mid = 62

Possible

answer = 62

Search Left

Iteration 4
-----------

mid = 58

Not Possible

Search Right

Iteration 5
-----------

mid = 60

Possible

answer = 60

Search Left

Loop Ends

Final Answer

60

==============================================================================
Key Takeaways
==============================================================================

• This is a Binary Search on Answer problem.
• We search for the minimum possible maximum painting time.
• Minimum answer = Largest board.
• Maximum answer = Sum of all boards.
• Greedy allocation checks whether a guessed answer is valid.
• Binary Search finds the first valid answer efficiently.

==============================================================================
Related Problems
==============================================================================

• GFG - Allocate Minimum Number of Pages
• LeetCode 410 - Split Array Largest Sum
• LeetCode 1011 - Capacity To Ship Packages Within D Days
• GFG - Aggressive Cows
*/