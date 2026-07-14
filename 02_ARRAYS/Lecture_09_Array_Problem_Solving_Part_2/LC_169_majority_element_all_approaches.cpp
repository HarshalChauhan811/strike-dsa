// Problem   --> Majority Element (LeetCode 169)
// Approach 1 --> Brute Force
// Approach -->
        // Har element ki frequency poore array me count karege.
        // Agar kisi element ki frequency n/2 se zyada hui,
        // to wahi Majority Element hoga.

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Har element ki frequency count karo.
        for (int i = 0; i < n; i++) {

            int freq = 0;

            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j]) {
                    freq++;
                }
            }

            // Majority Element mil gaya.
            if (freq > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

/*
Time Complexity  : O(n²)
Space Complexity : O(1)
*/



// Approach  2 --> Hashing
// Approach -->
        // Pehle har element ki frequency Hash Map me store karege.
        // Fir dubara array traverse karege.
        // Jis element ki frequency n/2 se zyada hogi,
        // wahi Majority Element hoga.

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;

        // Step 1 --> Frequency Count Karo.
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 2 --> Majority Element Find Karo.
        for (int i = 0; i < n; i++) {

            if (freq[nums[i]] > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(n)
*/


// Problem   --> Majority Element (LeetCode 169)
// Approach 3  --> Moore's Voting Algorithm (Optimal)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Approach -->
        // Candidate aur Count maintain karege.
        //
        // Count == 0
        // Matlab ab tak candidate ke saare votes cancel ho chuke hai.
        // Isliye current element ko naya candidate bana do.
        //
        // Agar current element candidate ke equal hai,
        // to support badhao.
        //
        // Agar different hai,
        // to ek vote cancel ho jayega.

        int candidate = 0;
        int count = 0;

        // Poore array ko traverse karo.
        for (int i = 0; i < nums.size(); i++) {

            // Agar candidate ke saare votes cancel ho gaye,
            // to current element ko naya candidate bana do.
            if (count == 0) {
                candidate = nums[i];
            }

            // Same candidate mila,
            // to support badha do.
            if (nums[i] == candidate) {
                count++;
            }

            // Different candidate mila,
            // to ek support cancel ho jayega.
            else {
                count--;
            }
        }

        // Majority Element return karo.
        return candidate;
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/