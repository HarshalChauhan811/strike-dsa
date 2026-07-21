#include <vector>
using namespace std;

/*
====================================================
          LeetCode 167 - Two Sum II
        Input Array Is Sorted
====================================================

Problem
----------------------------------------------------
Given a 1-indexed sorted array `numbers` and an
integer `target`, return the indices (1-based)
of the two numbers whose sum equals the target.

• Exactly one valid answer exists.
• The same element cannot be used twice.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : numbers = [2,7,11,15], target = 9
Output: [1,2]

Example 2
Input : numbers = [2,3,4], target = 6
Output: [1,3]

Example 3
Input : numbers = [-1,0], target = -1
Output: [1,2]

----------------------------------------------------
Approach 1 : Brute Force
----------------------------------------------------
Check every possible pair.

For every element, try pairing it with every
remaining element.

If their sum equals the target,
return their indices.

Time Complexity  : O(n²)

Space Complexity : O(1)

----------------------------------------------------
Approach 2 : Two Pointers (Optimal)
----------------------------------------------------
Since the array is already sorted, we can avoid
checking every pair.

Place:
• left pointer  -> Beginning
• right pointer -> End

Current Sum = numbers[left] + numbers[right]

Case 1:
Current Sum == Target

Return the answer.

------------------------------

Case 2:
Current Sum < Target

We need a larger sum.

Move Left Pointer.

left++

------------------------------

Case 3:
Current Sum > Target

We need a smaller sum.

Move Right Pointer.

right--

----------------------------------------------------
Why Two Pointers Works?
----------------------------------------------------
Because the array is sorted.

• Moving the Left Pointer always increases the sum.
• Moving the Right Pointer always decreases the sum.

Hence, every move is meaningful.

Unlike Brute Force,
we never revisit unnecessary pairs.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. left = 0
2. right = n - 1

3. While left < right

      sum = numbers[left] + numbers[right]

      if(sum == target)
            return answer

      else if(sum < target)
            left++

      else
            right--

----------------------------------------------------
Time Complexity
----------------------------------------------------
Brute Force : O(n²)

Optimal     : O(n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
Brute Force : O(1)

Optimal     : O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
✔ Two Pointers
✔ Sorted Array
✔ Opposite Direction Pointers

====================================================
                APPROACH 1
               (Brute Force)
====================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }

        return {};
    }
};
/*
====================================================
             APPROACH 2
        (Optimal - Two Pointers)
====================================================

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            // Target Found
            if (sum == target) {
                return {left + 1, right + 1};
            }

            // Need Bigger Sum
            else if (sum < target) {
                left++;
            }

            // Need Smaller Sum
            else {
                right--;
            }
        }

        return {};
    }
};

/*
====================================================
                SHORT DRY RUN
====================================================

numbers = [2,7,11,15]
target  = 9

----------------------------------------------------

left = 0
right = 3

sum = 2 + 15 = 17

17 > 9

Move Right Pointer

right = 2

----------------------------------------------------

left = 0
right = 2

sum = 2 + 11 = 13

13 > 9

Move Right Pointer

right = 1

----------------------------------------------------

left = 0
right = 1

sum = 2 + 7 = 9

Target Found ✔

Return [1,2]

====================================================
Interview Takeaways
====================================================

✔ Brute Force is acceptable only as the initial idea.

✔ Since the array is sorted, Two Pointers is more
  efficient than using a Hash Map.

✔ Two Pointers reduces the time complexity from
  O(n²) to O(n) while keeping O(1) extra space.

✔ This is one of the most important interview
  patterns for sorted arrays.

====================================================

*/