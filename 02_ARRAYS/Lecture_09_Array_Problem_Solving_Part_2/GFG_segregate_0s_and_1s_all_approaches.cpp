// Problem   --> Segregate 0s and 1s
// Approach  --> Brute Force (Using Temporary Array)
 // Approach -->
        // Ham ek temporary array banayege.
        // Pehle saare 0 temporary array me store karege.
        // Fir saare 1 temporary array me store karege.
        // Last me temporary array ko original array me copy kar dege.


class Solution {
public:
    void segregate0and1(vector<int> &arr) {

       
        int n = arr.size();

        vector<int> temp(n);

        int index = 0;

        // Step 1 --> Pehle saare 0 store karo.
        for (int i = 0; i < n; i++) {

            if (arr[i] == 0) {
                temp[index] = arr[i];
                index++;
            }
        }

        // Step 2 --> Fir saare 1 store karo.
        for (int i = 0; i < n; i++) {

            if (arr[i] == 1) {
                temp[index] = arr[i];
                index++;
            }
        }

        // Step 3 --> Temporary array ko original array me copy karo.
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(n)
*/



// Approach 2  --> Counting Method

class Solution {
public:

    void segregate0and1(vector<int> &arr) {

        // Approach -->
        // Pehle count karege ki array me kitne 0 hai.
        // Fir first countZero positions par 0 fill kar dege.
        // Remaining positions par 1 fill kar dege.

        int n = arr.size();

        int countZero = 0;

        // Step 1 --> Count total number of 0s.
        for (int i = 0; i < n; i++) {

            if (arr[i] == 0) {
                countZero++;
            }
        }

        // Step 2 --> First countZero positions par 0 fill karo.
        for (int i = 0; i < countZero; i++) {
            arr[i] = 0;
        }

        // Step 3 --> Remaining positions par 1 fill karo.
        for (int i = countZero; i < n; i++) {
            arr[i] = 1;
        }
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/


// Approach 3 --> Two Pointers (Optimal)
  // Approach -->
        // Left pointer ko 0 chahiye.
        // Right pointer ko 1 chahiye.
        //
        // Agar dono apni correct position par hai,
        // to pointer move kar do.
        //
        // Agar dono wrong position par hai,
        // to swap kar do.

class Solution {
public:

    void segregate0and1(vector<int> &arr) {

      

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {

            // Left already correct hai.
            if (arr[left] == 0) {
                left++;
            }

            // Right already correct hai.
            else if (arr[right] == 1) {
                right--;
            }

            // Dono wrong position par hai.
            else {

                swap(arr[left], arr[right]);

                left++;
                right--;
            }
        }
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/