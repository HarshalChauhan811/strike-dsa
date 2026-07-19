#include <vector>
using namespace std;

/*
====================================================
      LeetCode 35 - Search Insert Position
====================================================

Problem
----------------------------------------------------
Given a sorted array of distinct integers `nums`
and an integer `target`, return the index if the
target is found.

Otherwise, return the index where it should be
inserted to maintain the sorted order.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : nums = [1,3,5,6], target = 5
Output: 2

Example 2
Input : nums = [1,3,5,6], target = 2
Output: 1

Example 3 (Edge Case)
Input : nums = [1,3,5,6], target = 7
Output: 4

----------------------------------------------------
Approach
----------------------------------------------------
Use Binary Search to find the Lower Bound.

The Lower Bound is the first element that is
greater than or equal to the target.

Whenever nums[mid] >= target:
• Store the current index as a possible answer.
• Continue searching on the Left.

Otherwise:
• Search on the Right.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize answer = nums.size().
2. Perform Binary Search.
3. If nums[mid] >= target:
      • Store current index.
      • Search Left.
4. Otherwise:
      • Search Right.
5. Return answer.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(1)

Average Case : O(log n)

Worst Case   : O(log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
✔ Binary Search
✔ Lower Bound
✔ Answer Search

====================================================
                      CODE
====================================================
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        // Default insertion position
        int answer = nums.size();

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Possible answer found
            if (nums[mid] >= target) {

                answer = mid;

                // Search Left
                end = mid - 1;
            }
            else {

                // Search Right
                start = mid + 1;
            }
        }

        return answer;
    }
};

/*
====================================================
                  SHORT DRY RUN
====================================================

Input:
nums   = [1,3,5,6]
target = 2

----------------------------------------------------
Iteration 1

start = 0
end = 3

mid = 1

nums[mid] = 3

3 >= 2

answer = 1

Search Left

end = 0

----------------------------------------------------
Iteration 2

start = 0
end = 0

mid = 0

nums[mid] = 1

1 < 2

Search Right

start = 1

----------------------------------------------------
Loop Ends

start > end

Return answer = 1

====================================================
*/