/*
====================================================
PROBLEM: Rotate Array Clockwise by k
====================================================
GFG Link:
https://www.geeksforgeeks.org/problems/rotate-array-clockwise/1

LeetCode Equivalent:
189. Rotate Array
====================================================
*/

// Approach 1 --> Brute Force Approach --> Rotate by One, k Times


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // Approach -->
        // Ham ek baar rotate karna jaante hai.
        // Agar k baar rotate karna hai,
        // to wahi process k baar repeat kar dege.

        int n = nums.size();

        // Agar k array ke size se bada hai,
        // to extra rotations ka koi fayda nahi.
        // Isliye effective rotations hi nikal lo.
        k = k % n;

        // Rotate by One, k times
        for (int i = 0; i < k; i++) {

            // Last element ko save kar lo
            // kyunki shift karte time ye overwrite ho jayega.
            int last = nums[n - 1];

            // Saare elements ko ek position right shift karo.
            // Right se shift kar rahe hai taki data overwrite na ho.
            for (int j = n - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }

            // Saved last element ko first position par rakh do.
            nums[0] = last;
        }
    }
};

/*
Time Complexity  : O(n * k)
Space Complexity : O(1)
*/



//  Approach 2 --> Using Temporary Array

// Ham ek temporary array banayege.
// Har element ko uski new position par rakh dege.
// New Position = (Current Index + k) % n
// Last me temporary array ko
// original array me copy kar dege.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        vector<int> temp(n);

        // Har element ko uski new position par rakho
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        // Temp array ko original array me copy karo
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};

// Time  : O(n)
// Space : O(n)


// Approach 3 --> Reverse Algorithm (Optimal)

// Approach -->
// Pehle poore array ko reverse karege.
// Fir first k elements ko reverse karege.
// Last me remaining elements ko reverse karege.


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

       .

        int n = nums.size();

        // Extra rotations ko skip karne ke liye
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
Time Complexity  : O(n)
Space Complexity : O(1)
*/


// Using --> Reverse fn 

class Solution {
public:

    // Reverse Function -->
    // Left aur Right pointer use karege.
    // Dono pointers ke elements ko swap karege.
    // Har swap ke baad
    // Left ko aage aur Right ko peeche move karege.
    // Jab dono pointers mil jayenge,
    // tab reverse complete ho jayega.

    void reverseArray(vector<int>& nums, int left, int right) {

        // Jab tak Left aur Right cross na kare
        while (left < right) {

            // Left aur Right element ko swap karo
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            // Left ko aage aur Right ko peeche move karo
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        // Approach -->
        // Pehle poore array ko reverse karege.
        // Fir first k elements ko reverse karege.
        // Last me remaining elements ko reverse karege.
        // Isse array Right Rotate ho jayega.

        int n = nums.size();

        // Agar k array ke size se bada hai,
        // to extra rotations ka koi fayda nahi.
        // Isliye effective rotations hi nikal lo.
        k = k % n;

        // Step 1 --> Poora array reverse karo.
        reverseArray(nums, 0, n - 1);

        // Step 2 --> First k elements reverse karo.
        reverseArray(nums, 0, k - 1);

        // Step 3 --> Remaining elements reverse karo.
        reverseArray(nums, k, n - 1);
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/