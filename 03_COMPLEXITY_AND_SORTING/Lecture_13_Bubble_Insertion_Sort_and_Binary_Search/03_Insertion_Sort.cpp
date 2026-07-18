#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Sort an Array
====================================================

LeetCode : 912. Sort an Array

Algorithm : Insertion Sort

====================================================
Definition

Insertion Sort ek comparison-based sorting
algorithm hai.

Ye array ko gradually sort karta hai.
Har iteration me current element ko
already sorted part me uski correct
position par insert kiya jata hai.

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
Approach --> Insertion Sort

1. Pehla element already sorted maan lo.

2. Current element ko uthao.

3. Sorted part me left side move karo.

4. Jab tak previous element bada ho,
   swap karte raho.

5. Correct position milte hi stop kar do.

Time Complexity

Best Case    : O(n)
Average Case : O(n²)
Worst Case   : O(n²)

Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Assume first element is already sorted
        for (int i = 1; i < n; i++) {

            // Insert current element into sorted part
            for (int j = i; j > 0; j--) {

                // Move current element towards left
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }

                // Correct position found
                else {
                    break;
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
Initial

[5,2,3,1]

---------------------------------
Pass 1

Current = 2

Swap(2,5)

[2,5,3,1]

---------------------------------
Pass 2

Current = 3

Swap(3,5)

[2,3,5,1]

---------------------------------
Pass 3

Current = 1

Swap(1,5)

[2,3,1,5]

Swap(1,3)

[2,1,3,5]

Swap(1,2)

[1,2,3,5]

---------------------------------

Final Output

[1,2,3,5]

====================================================
Summary

Algorithm        : Insertion Sort
LeetCode Problem : 912 - Sort an Array
Time Complexity  : Best : O(n)
                   Average : O(n²)
                   Worst : O(n²)
Space Complexity : O(1)
Stable           : Yes
In-Place         : Yes
Adaptive         : Yes

====================================================
*/