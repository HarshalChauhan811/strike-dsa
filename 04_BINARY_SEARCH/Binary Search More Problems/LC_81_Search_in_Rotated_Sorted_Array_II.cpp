#include <bits/stdc++.h>
using namespace std;

/*
====================================================
   LeetCode 81 - Search in Rotated Sorted Array II
====================================================

Problem Statement
----------------------------------------------------
Given a rotated sorted array nums that may contain
duplicates, return true if target exists in the
array, otherwise return false.

The array may contain duplicate elements.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
nums = [2,5,6,0,0,1,2]
target = 0

Output:
true

Reason:
Target 0 exists in the array.

----------------------------------------------------

Example 2

Input:
nums = [2,5,6,0,0,1,2]
target = 3

Output:
false

Reason:
Target does not exist in the array.

----------------------------------------------------

Example 3

Input:
nums = [1,1,1,3,1]
target = 3

Output:
true

Reason:
Initially,

start = 0
mid = 2
end = 4

nums[start] = 1
nums[mid]   = 1
nums[end]   = 1

Yaha hum decide hi nahi kar sakte
ki left sorted hai ya right sorted,
kyuki tino values same hain.

Isliye:

start++;
end--;

karke duplicate ko safely remove
kar dete hain aur search continue
karte hain.

----------------------------------------------------

Example 4

Input:
nums = [1,0,1,1,1]
target = 0

Output:
true

Reason:
Duplicates ki wajah se direction
clear nahi hoti, lekin duplicate
remove karte hue target mil jata hai.

----------------------------------------------------

Example 5

Input:
nums = [1,1,1,1,1]
target = 2

Output:
false

Reason:
Target array me exist nahi karta.

----------------------------------------------------
Approach
----------------------------------------------------
Modified Binary Search

Idea:
- Har iteration me check karo
  target mil gaya ya nahi.

- Agar start, mid aur end tino
  same hain,
  to Binary Search direction
  decide nahi kar sakti.

- Isliye duplicate values ko
  safely remove karo.

- Uske baad dekho
  kaunsa half sorted hai.

- Agar target sorted half me hai,
  to wahi search karo.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Find middle index.

2. Agar target mil jaye,
   return true.

3. Agar start == mid == end:
      Duplicate remove karo.

4. Left sorted ya
   right sorted identify karo.

5. Target jis side ho,
   us side search karo.

6. Agar target na mile,
   return false.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
Duplicate na ho to
har baar ek half sorted hota hai.

Lekin duplicates ki wajah se
kabhi-kabhi direction clear
nahi hoti.

Example:

nums = [1,1,1,3,1]

           mid

start = 1
mid   = 1
end   = 1

Yaha ye decide hi nahi kar sakte
ki minimum ya target kis side hai.

Isliye:

start++;
end--;

karke ek duplicate remove karte hain.

Ye target ko miss nahi karega,
bas search space thodi chhoti
ho jayegi.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(1)

Average Case : O(log n)

Worst Case   : O(n)

Reason:
Agar bahut saare duplicates hon,
to har iteration me sirf ek-ek
duplicate remove karna pad sakta hai.

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
    bool search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Target mil gaya
            if (nums[mid] == target) {
                return true;
            }

            // Agar start, mid aur end tino same hain,
            // to decide nahi kar sakte
            // left sorted hai ya right sorted.
            //
            // Example:
            // nums = [1,1,1,3,1]
            //
            // Isliye ek-ek duplicate
            // dono side se remove kar do.
            if (nums[start] == nums[mid] &&
                nums[mid] == nums[end]) {

                start++;
                end--;
            }

            // Left half sorted
            else if (nums[start] <= nums[mid]) {

                // Target left half me hai
                if (nums[start] <= target &&
                    target < nums[mid]) {

                    end = mid - 1;
                }
                else {

                    start = mid + 1;
                }
            }

            // Right half sorted
            else {

                // Target right half me hai
                if (nums[mid] < target &&
                    target <= nums[end]) {

                    start = mid + 1;
                }
                else {

                    end = mid - 1;
                }
            }
        }

        return false;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Modified Binary Search
LeetCode Problem : 81 - Search in Rotated Sorted Array II

Time Complexity
Best Case       : O(1)
Average Case    : O(log n)
Worst Case      : O(n)

Space Complexity: O(1)

Concepts Used:
✔ Binary Search
✔ Rotated Sorted Array
✔ Duplicates
✔ Sorted Half Detection
✔ Search Space Reduction
*/