class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        // Sort karne se same elements paas aa jayenge
        sort(nums.begin(), nums.end());

        // Agar koi element 2 se zyada baar hai,
        // to 2 parts me dono ko distinct rakhna possible nahi hai
        for(int i = 2; i < n; i++) {

            if(nums[i] == nums[i - 2])
                return false;
        }

        return true;
    }
};