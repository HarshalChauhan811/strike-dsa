class Solution {
public:
    int missingNumber(vector<int>& arr) {

        // Approach -->
        // Ham 0 se n tak har expected number ko check karege
        // Fir us number ko poore array me search karege
        // Jo number array me nahi milega wahi hamara missing number hoga

        int n = arr.size();

        // 0 se n tak saare expected numbers check karo
        for (int i = 0; i <= n; i++) {

            // Maan lo abhi ye number array me nahi mila hai
            bool found = false;

            // Current expected number ko poore array me search karo
            for (int j = 0; j < n; j++) {

                // Agar number mil gaya to found true kar do
                // Aur aage search karne ki zarurat nahi hai
                if (arr[j] == i) {
                    found = true;
                    break;
                }
            }

            // Agar poora array check karne ke baad bhi number nahi mila
            // To wahi hamara missing number hai
            if (!found) {
                return i;
            }
        }

        // Ye line valid input me kabhi execute nahi hogi
        return -1;
    }
};




// Approach 2 

class Solution {
public:
    int missingNumber(vector<int>& arr) {

        // Approach:
        // 1. Calculate the sum of all elements present in the array (ActualSum).
        // 2. Calculate the sum of numbers from 0 to n (totalSum).
        // 3. The difference between totalSum and ActualSum
        //    will be the missing number.

        int n = arr.size();
        int ActualSum = 0;
        int totalSum = 0;

        // Calculate Actual Sum
        for (int i = 0; i < n; i++) {
            ActualSum += arr[i];
        }

        // Calculate Expected Sum (0 to n)
        totalSum = n * (n + 1) / 2;

        // Missing Number = Expected Sum - Actual Sum
        return totalSum - ActualSum;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)



// Approach 3 


class Solution {
public:
    int missingNumber(vector<int>& arr) {

        // Approach -->
        // Ham XOR ki help se same numbers ko cancel kar dege.
        // Ek taraf Expected Numbers (0 to n) ka XOR karege.
        // Dusri taraf Array ke Actual Numbers ka XOR karege.
        // Jo number sirf ek baar bachega wahi missing number hoga.

        int n = arr.size();

        // ans ko n se initialize kar diya,
        // taki expected numbers me last number (n) cover ho jaye
        // aur loop sirf 0 se n-1 tak chalana pade.
        int ans = n;

        // Ek hi loop me Expected Numbers aur Actual Numbers
        // dono ka XOR kar rahe hai.
        for (int i = 0; i < n; i++) {

            // Expected Number ka XOR
            ans ^= i;

            // Actual Number ka XOR
            ans ^= arr[i];
        }

        // Saare common numbers cancel ho jayenge,
        // sirf missing number bachega.
        return ans;
    }
};