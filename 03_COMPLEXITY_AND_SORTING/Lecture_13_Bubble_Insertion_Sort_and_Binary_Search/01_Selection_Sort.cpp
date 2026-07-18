#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Sort an Array
====================================================

LeetCode : 912. Sort an Array

Algorithm : Selection Sort

====================================================
Definition

Selection Sort ek comparison-based sorting
algorithm hai.

Har iteration me unsorted part se
minimum element find kiya jata hai aur
use current position par place kar diya jata hai.

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
Approach --> Selection Sort

1. Array ko do parts me divide karo.
   - Sorted Part
   - Unsorted Part

2. Current index ko minimum maan lo.

3. Remaining array me actual minimum
   element find karo.

4. Minimum element ko current index ke
   saath swap kar do.

5. Ye process har position ke liye repeat karo.

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

        // Traverse Complete Array
        for (int i = 0; i < n - 1; i++) {

            // Assume current index contains minimum element
            int minIndex = i;

            // Find actual minimum element
            for (int j = i + 1; j < n; j++) {

                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            // Place minimum element at its correct position
            swap(nums[i], nums[minIndex]);
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

Current Index = 0

Minimum = 1

Swap(5,1)

[1,2,3,5]

---------------------------------
Pass 2

Current Index = 1

Minimum = 2

Already Correct

[1,2,3,5]

---------------------------------
Pass 3

Current Index = 2

Minimum = 3

Already Correct

[1,2,3,5]

---------------------------------

Final Output

[1,2,3,5]

====================================================
Summary

Algorithm        : Selection Sort
LeetCode Problem : 912 - Sort an Array
Time Complexity  : O(n²)
Space Complexity : O(1)
Stable           : No
In-Place         : Yes
Adaptive         : No

====================================================
*/