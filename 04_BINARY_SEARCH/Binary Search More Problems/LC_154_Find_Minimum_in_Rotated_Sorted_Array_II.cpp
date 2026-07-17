#include <bits/stdc++.h>
using namespace std;

/*
====================================================
   LeetCode 154 - Find Minimum in Rotated Sorted Array II
====================================================

Problem Statement
----------------------------------------------------
Suppose an array of integers is sorted in
ascending order and then rotated.

The array may contain duplicate elements.

Return the minimum element.

The solution should be as efficient as possible.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
nums = [1,3,5]

Output:
1

Reason:
Array rotate nahi hua hai.
Pehla element hi minimum hai.

----------------------------------------------------

Example 2

Input:
nums = [2,2,2,0,1]

Output:
0

Reason:
Rotation ke baad 0
sabse chhota element hai.

----------------------------------------------------

Example 3

Input:
nums = [3,3,1,3]

Output:
1

Reason:
Duplicate values hone ke baad bhi
minimum element 1 hi hai.

----------------------------------------------------

Example 4

Input:
nums = [10,1,10,10,10]

Output:
1

Reason:
Duplicates ki wajah se
Binary Search ko carefully
handle karna padta hai.

----------------------------------------------------

Example 5

Input:
nums = [2,2,2,2,2]

Output:
2

Reason:
Saare elements same hain,
isliye wahi minimum hai.

----------------------------------------------------
Approach
----------------------------------------------------
Modified Binary Search

Idea:
- nums[mid] ko nums[end] se compare karo.

- Agar nums[mid] > nums[end]:
  Minimum right side me hoga.

- Agar nums[mid] < nums[end]:
  Minimum left side (including mid)
  me ho sakta hai.

- Agar nums[mid] == nums[end]:
  Decide nahi kar sakte.
  Isliye ek duplicate ko safely
  remove kar do.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize:
   start = 0
   end = n - 1

2. Find the middle index.

3. Compare nums[mid] with nums[end].

4. According to the comparison,
   search space ko reduce karo.

5. Jab start == end ho jaye,
   wahi minimum element hoga.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
Rotated sorted array me
minimum sirf ek side hota hai.

nums[mid] aur nums[end]
ko compare karke hum decide
kar sakte hain kis side search
continue karna hai.

Bas duplicate case me
direction clear nahi hoti,
isliye ek duplicate remove
kar dete hain.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(1)

Average Case : O(log n)

Worst Case   : O(n)

Reason:
Agar bahut saare duplicates hon,
to har baar sirf ek element
remove karna pad sakta hai.

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

Reason:
Koi extra memory use nahi hoti.

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search
Rotated Sorted Array
Duplicates
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            // Agar mid end se bada hai,
            // to minimum right side me hoga.
            if (nums[mid] > nums[end]) {

                start = mid + 1;
            }

            // Agar mid end se chhota hai,
            // to mid minimum ho sakta hai.
            // Isliye left side (including mid)
            // me search continue karo.
            else if (nums[mid] < nums[end]) {

                end = mid;
            }

            // nums[mid] == nums[end]
            // Yaha decide nahi kar sakte
            // minimum kis side hai,
            // kyuki duplicate values hain.
            // Isliye ek duplicate ko
            // safely remove kar do.
            else {

                end--;
            }
        }

        return nums[start];
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Modified Binary Search
LeetCode Problem : 154 - Find Minimum in Rotated Sorted Array II

Time Complexity
Best Case       : O(1)
Average Case    : O(log n)
Worst Case      : O(n)

Space Complexity: O(1)

Concepts Used:
✔ Binary Search
✔ Rotated Sorted Array
✔ Duplicates
✔ Search Space Reduction
*/