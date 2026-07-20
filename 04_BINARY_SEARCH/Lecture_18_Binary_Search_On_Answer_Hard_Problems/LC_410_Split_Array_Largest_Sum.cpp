#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// LeetCode 410. Split Array Largest Sum
// Pattern    : Binary Search on Answer
// Difficulty : Hard
// Time       : O(n × log(sum))
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Given an integer array nums and an integer k.

Split the array into exactly k
non-empty continuous subarrays.

Return the minimum possible value
of the largest subarray sum.

Examples
--------

Example 1

Input:
nums = [7,2,5,10,8]
k = 2

Output:
18

Explanation:

Split:

[7,2,5]   [10,8]

Largest Subarray Sum = 18


Example 2

Input:
nums = [1,2,3,4,5]
k = 2

Output:
9

Explanation:

Split:

[1,2,3]   [4,5]

Largest Subarray Sum = 9


Example 3

Input:
nums = [1,4,4]
k = 3

Output:
4

Explanation:

Each element forms its own subarray.

Largest Sum = 4
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Try every possible value of the
largest allowed subarray sum.

The minimum possible answer is the
largest element.

The maximum possible answer is the
sum of all elements.

For every value,
check whether the array can be split
into at most k subarrays.

The first valid value is the answer.

Algorithm
---------
1. Find the largest element.
2. Find the total sum.
3. Try every value from largest element to total sum.
4. Check if partition is possible.
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

Trying every possible answer
is inefficient.

Binary Search reduces the
number of candidate answers
significantly.
*/

/*
==============================================================================
Optimal Approach (Binary Search on Answer)
==============================================================================

Idea
----
We are NOT searching for an array element.

We are searching for the minimum
possible largest subarray sum.

Suppose the maximum allowed
subarray sum is X.

Can the array be split into
k or fewer subarrays?

If YES,
try a smaller answer.

If NO,
increase the allowed sum.

Search Space
------------

Minimum Answer
Largest Element

Maximum Answer
Sum of All Elements

Algorithm
---------
1. start = Largest element.
2. end = Sum of all elements.
3. Find mid.
4. Check whether partition is possible.
5. If possible:
      Save answer.
      Search left.
6. Otherwise:
      Search right.

Why Binary Search Works?
------------------------
As the allowed maximum sum increases,

creating partitions becomes easier.

Maximum Sum ↑

Required Partitions ↓

This is a monotonic property.

Binary Search efficiently finds
the minimum valid answer.
*/

class Solution {
public:

    // Check if the array can be split
    // into at most k partitions
    bool possible(vector<int>& nums, int k, int maxSum) {

        int partitions = 1;
        int currentSum = 0;

        for (int num : nums) {

            // Add to current partition
            if (currentSum + num <= maxSum) {

                currentSum += num;
            }

            // Create a new partition
            else {

                partitions++;
                currentSum = num;
            }
        }

        return partitions <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Current sum works
            if (possible(nums, k, mid)) {

                answer = mid;
                end = mid - 1;
            }

            // Increase allowed sum
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

nums = [7,2,5,10,8]

k = 2

Search Space

start = 10

end = 32

Iteration 1
-----------

mid = 21

Partition 1

7 + 2 + 5 = 14

+10 exceeds 21

Partition 2

10 + 8 = 18

Possible

answer = 21

Search Left

Iteration 2
-----------

mid = 15

Need 3 partitions

Not Possible

Search Right

Iteration 3
-----------

mid = 18

Partition 1

7 + 2 + 5 = 14

Partition 2

10 + 8 = 18

Possible

answer = 18

Search Left

Iteration 4
-----------

mid = 16

Need 3 partitions

Not Possible

Search Right

Iteration 5
-----------

mid = 17

Need 3 partitions

Not Possible

Search Right

Loop Ends

Final Answer

18

==============================================================================
Key Takeaways
==============================================================================

• This is a Binary Search on Answer problem.
• Minimum answer = Largest element.
• Maximum answer = Sum of all elements.
• Greedy partition checks whether a guessed answer is valid.
• Binary Search finds the minimum valid largest subarray sum.
• Maximum allowed sum and required partitions form a monotonic relationship.

==============================================================================
Related Problems
==============================================================================

• GFG - Allocate Minimum Number of Pages
• GFG - Painter's Partition Problem
• LeetCode 1011 - Capacity To Ship Packages Within D Days
• LeetCode 875 - Koko Eating Bananas
*/