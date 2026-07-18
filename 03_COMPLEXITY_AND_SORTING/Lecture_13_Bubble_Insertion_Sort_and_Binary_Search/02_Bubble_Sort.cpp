#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Sort an Array
====================================================

LeetCode : 912. Sort an Array

Algorithm : Bubble Sort

====================================================
Definition

Bubble Sort ek comparison-based sorting
algorithm hai.

Ye baar-baar adjacent elements ko compare
karta hai aur agar woh wrong order me hote
hain to unhe swap kar deta hai.

Har pass ke baad sabse bada element
apni correct position par pahunch jata hai.

====================================================
Example 1

Input

nums = [5,2,3,1]

Output

[1,2,3,5]

----------------------------------------------------
Example 2

Input

nums = [5,1,1,2,0,0]

Output

[0,0,1,1,2,5]

----------------------------------------------------
Example 3

Input

nums = [3,2,1]

Output

[1,2,3]

====================================================
Approach --> Bubble Sort

1. Array ko multiple passes me traverse karo.

2. Har pass me adjacent elements compare karo.

3. Agar left element bada ho,
   to dono ko swap kar do.

4. Har pass ke baad largest element
   end me pahunch jata hai.

5. Total (n - 1) passes ke baad
   array completely sorted ho jata hai.

Time Complexity

Best Case    : O(n²)
Average Case : O(n²)
Worst Case   : O(n²)

Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Total n - 1 passes
        for (int i = 0; i < n - 1; i++) {

            // Compare adjacent elements
            for (int j = 0; j < n - i - 1; j++) {

                // Swap if elements are in wrong order
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        return nums;
    }
};

/*
====================================================
Dry Run

Input

nums = [5,2,3,1]

---------------------------------
Pass 1

[5,2,3,1]

Swap(5,2)

[2,5,3,1]

Swap(5,3)

[2,3,5,1]

Swap(5,1)

[2,3,1,5]

---------------------------------
Pass 2

[2,3,1,5]

Swap(3,1)

[2,1,3,5]

---------------------------------
Pass 3

[2,1,3,5]

Swap(2,1)

[1,2,3,5]

---------------------------------

Final Output

[1,2,3,5]

====================================================
Summary

Algorithm        : Bubble Sort
LeetCode Problem : 912 - Sort an Array
Time Complexity  : O(n²)
Space Complexity : O(1)
Stable           : Yes
In-Place         : Yes
Adaptive         : No

====================================================
*/