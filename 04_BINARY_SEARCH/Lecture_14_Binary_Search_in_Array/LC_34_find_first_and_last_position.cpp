#include <vector>
using namespace std;

/*
====================================================
      LeetCode 34 - Find First and Last Position
          of Element in Sorted Array
====================================================

Problem
----------------------------------------------------
Given a sorted integer array `nums` and a `target`,
return the first and last position of the target.

If the target is not found, return [-1, -1].

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2
Input : nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3 (Edge Case)
Input : nums = [2,2], target = 2
Output: [0,1]

----------------------------------------------------
Approach
----------------------------------------------------
Perform Binary Search twice.

• First Binary Search  -> Find First Occurrence.
• Second Binary Search -> Find Last Occurrence.

Whenever the target is found:

• First Occurrence:
  Store the answer and continue searching on the Left.

• Last Occurrence:
  Store the answer and continue searching on the Right.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize answer as {-1, -1}.
2. Find the First Occurrence.
3. Reset the search space.
4. Find the Last Occurrence.
5. Return the answer.

----------------------------------------------------
Time Complexity
----------------------------------------------------
First Binary Search  : O(log n)

Second Binary Search : O(log n)

Overall              : O(log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
✔ Binary Search
✔ First Occurrence
✔ Last Occurrence

====================================================
                      CODE
====================================================
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2, -1);

        int start = 0;
        int end = nums.size() - 1;

        // Find First Occurrence
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {

                ans[0] = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {

                start = mid + 1;
            }
            else {

                end = mid - 1;
            }
        }

        // Reset Search Space
        start = 0;
        end = nums.size() - 1;

        // Find Last Occurrence
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {

                ans[1] = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {

                start = mid + 1;
            }
            else {

                end = mid - 1;
            }
        }

        return ans;
    }
};

/*
====================================================
                  SHORT DRY RUN
====================================================

Input:
nums   = [5,7,7,8,8,10]
target = 8

----------------------------------------------------
Finding First Occurrence

start = 0, end = 5

mid = 2 -> nums[mid] = 7

7 < 8

Move Right

start = 3

-------------------------

mid = 4 -> nums[mid] = 8

Target Found

ans[0] = 4

Search Left

end = 3

-------------------------

mid = 3 -> nums[mid] = 8

Target Found

ans[0] = 3

Search Left

end = 2

First Occurrence = 3

----------------------------------------------------
Finding Last Occurrence

start = 0, end = 5

mid = 2 -> nums[mid] = 7

7 < 8

Move Right

start = 3

-------------------------

mid = 4 -> nums[mid] = 8

Target Found

ans[1] = 4

Search Right

start = 5

-------------------------

mid = 5 -> nums[mid] = 10

10 > 8

Move Left

end = 4

Last Occurrence = 4

----------------------------------------------------
Final Answer

[3,4]

====================================================
*/