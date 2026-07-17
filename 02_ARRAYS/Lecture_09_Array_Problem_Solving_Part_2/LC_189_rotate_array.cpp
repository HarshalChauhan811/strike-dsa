#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Rotate Array
====================================================

LeetCode : 189. Rotate Array

Related Problem
GFG : Rotate Array Clockwise

====================================================
Definition

Given an integer array nums, rotate the array
to the right by k steps, where k is non-negative.

Right Rotation ka matlab hai ki har element
ek position right move karega aur last element
first position par aa jayega.

====================================================
Example 1

Input
nums = [1,2,3,4,5,6,7]
k = 3

Output
[5,6,7,1,2,3,4]

----------------------------------------------------
Example 2

Input
nums = [-1,-100,3,99]
k = 2

Output
[3,99,-1,-100]

----------------------------------------------------
Example 3

Input
nums = [1,2]
k = 1

Output
[2,1]

====================================================
Approach 1 --> Brute Force (Rotate by One, k Times)

1. Hume ek baar Right Rotate karna aata hai.
2. Agar k baar rotate karna hai,
   to wahi process k baar repeat kar denge.
3. Har rotation me
   - Last element save karenge.
   - Array ko right shift karenge.
   - Saved element ko first index par rakh denge.

Time Complexity  : O(n × k)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Effective rotations
        k = k % n;

        // Rotate by One, k Times
        for (int i = 0; i < k; i++) {

            // Last element save kar lo
            int last = nums[n - 1];

            // Right Shift
            for (int j = n - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }

            // Saved element ko first index par rakho
            nums[0] = last;
        }
    }
};

/*
====================================================
Dry Run

Input

nums = [1,2,3,4,5]
k = 2

---------------------------------
Initial Array

[1,2,3,4,5]

---------------------------------
Rotation 1

Last = 5

Shift

[1,2,3,4,4]
[1,2,3,3,4]
[1,2,2,3,4]
[1,1,2,3,4]

Place Last

[5,1,2,3,4]

---------------------------------
Rotation 2

Last = 4

Shift

[5,1,2,3,3]
[5,1,2,2,3]
[5,1,1,2,3]
[5,5,1,2,3]

Place Last

[4,5,1,2,3]

---------------------------------
Final Output

[4,5,1,2,3]

====================================================
*/


#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 2 --> Using Temporary Array

Idea

Ek temporary array banayenge.

Har element ko uski new position par rakh denge.

New Index = (Current Index + k) % n

Last me temporary array ko original
array me copy kar denge.

Time Complexity  : O(n)
Space Complexity : O(n)

====================================================
*/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Effective rotations
        k = k % n;

        // Temporary Array
        vector<int> temp(n);

        // Har element ko uski new position par rakho
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        // Copy back into original array
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};

/*
====================================================
Dry Run

Input

nums = [1,2,3,4,5]
k = 2

---------------------------------
Initial Array

[1,2,3,4,5]

New Position Formula

(Current Index + k) % n

---------------------------------

i = 0

temp[(0 + 2) % 5] = 1

temp = [_,_,1,_,_]

---------------------------------

i = 1

temp[(1 + 2) % 5] = 2

temp = [_,_,1,2,_]

---------------------------------

i = 2

temp[(2 + 2) % 5] = 3

temp = [_,_,1,2,3]

---------------------------------

i = 3

temp[(3 + 2) % 5] = 4

temp = [4,_,1,2,3]

---------------------------------

i = 4

temp[(4 + 2) % 5] = 5

temp = [4,5,1,2,3]

---------------------------------

Copy temp into nums

nums = [4,5,1,2,3]

Final Output

[4,5,1,2,3]

====================================================
*/


#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 3 --> Reverse Algorithm (Optimal)

Idea

1. Pehle poore array ko reverse karo.
2. Fir first k elements ko reverse karo.
3. Last me remaining elements ko reverse karo.

Isse array Right Rotate ho jayega.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Effective rotations
        k = k % n;

        // Step 1 --> Reverse complete array
        reverse(nums.begin(), nums.end());

        // Step 2 --> Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3 --> Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

/*
====================================================
Dry Run

Input

nums = [1,2,3,4,5]
k = 2

---------------------------------
Step 1

Reverse Complete Array

[5,4,3,2,1]

---------------------------------
Step 2

Reverse First k Elements

Reverse First 2 Elements

[4,5,3,2,1]

---------------------------------
Step 3

Reverse Remaining Elements

Reverse [3,2,1]

[4,5,1,2,3]

---------------------------------

Final Output

[4,5,1,2,3]

====================================================
*/



#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 4 --> Reverse Function (Without STL)

Idea

STL reverse() use karne ki jagah
khud ka Reverse Function banayenge.

1. Left aur Right pointer use karenge.
2. Dono elements ko swap karenge.
3. Left ko aage aur Right ko peeche move karenge.
4. Jab Left >= Right ho jayega,
   tab reverse complete ho jayega.

Rotation Steps

1. Reverse complete array.
2. Reverse first k elements.
3. Reverse remaining elements.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    // Custom Reverse Function
    void reverseArray(vector<int>& nums, int left, int right) {

        while (left < right) {

            // Swap
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Effective rotations
        k = k % n;

        // Step 1 --> Reverse Complete Array
        reverseArray(nums, 0, n - 1);

        // Step 2 --> Reverse First k Elements
        reverseArray(nums, 0, k - 1);

        // Step 3 --> Reverse Remaining Elements
        reverseArray(nums, k, n - 1);
    }
};

/*
====================================================
Dry Run

Input

nums = [1,2,3,4,5]
k = 2

---------------------------------
Step 1

Reverse Complete Array

[5,4,3,2,1]

---------------------------------
Step 2

Reverse First 2 Elements

[4,5,3,2,1]

---------------------------------
Step 3

Reverse Remaining Elements

[4,5,1,2,3]

---------------------------------

Final Output

[4,5,1,2,3]

====================================================
*/