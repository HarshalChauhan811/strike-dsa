// Problem   --> Sum of Unique Elements (LeetCode 1748)

// Approach 1 --> Brute Force (Count Frequency for Every Element)
// Approach -->
// Har element ki frequency poore array me count karege.
// Agar frequency 1 mili,
// to us element ko answer me add kar dege.


class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        // Har element ke liye frequency count karo.
        for (int i = 0; i < n; i++) {

            int freq = 0;

            // Current element kitni baar aaya hai
            // uski frequency count karo.
            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j]) {
                    freq++;
                }
            }

            // Agar sirf ek baar aaya hai
            // to answer me add kar do.
            if (freq == 1) {
                sum += nums[i];
            }
        }

        return sum;
    }
};

/*
Time Complexity  : O(n²)
Space Complexity : O(1)
*/


// Approach 2  --> Hashing (Frequency Array)
// Approach -->
        // Pehle har element ki frequency store karege.
        // Fir dubara array traverse karege.
        // Jis element ki frequency 1 hogi,
        // ussi ko answer me add kar dege.

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        vector<int> freq(101, 0);

        // Frequency count karo.
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int sum = 0;

        // Unique elements ka sum nikalo.
        for (int i = 0; i < nums.size(); i++) {

            if (freq[nums[i]] == 1) {
                sum += nums[i];
            }
        }

        return sum;
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/