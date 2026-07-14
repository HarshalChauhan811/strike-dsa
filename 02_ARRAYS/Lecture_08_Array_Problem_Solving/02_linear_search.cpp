// GFG Problem --> Search an Element in an Array

// Approach -->
// Array ke har element ko
// ek-ek karke check karege.
//
// Agar current element target ke equal mil gaya
// to uska index return kar dege.
//
// Agar poora array traverse karne ke baad bhi
// target nahi mila
// to -1 return kar dege.

class Solution {
public:

    int search(int arr[], int n, int target) {

        // Array ke saare elements ko traverse karo
        for (int i = 0; i < n; i++) {

            // Agar target mil gaya
            // to uska index return kar do.
            if (arr[i] == target) {
                return i;
            }
        }

        // Agar target poore array me nahi mila
        return -1;
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/