// Problem   --> Second Largest Element (Gfg) Link --> https://www.geeksforgeeks.org/problems/second-largest3735/1
// Approach  --> Two Traversals (Without Sorting)

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {

        // Approach -->
        // Pehle Largest element find karege.
        // Fir dubara array traverse karege.
        // Largest se chhota aur sabse bada element hi
        // Second Largest hoga.

        int n = arr.size();

        int largest = arr[0];

        // Step 1 --> Largest Find Karo
        for (int i = 1; i < n; i++) {

            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        int secondLargest = -1;

        // Step 2 --> Second Largest Find Karo
        for (int i = 0; i < n; i++) {

            if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/