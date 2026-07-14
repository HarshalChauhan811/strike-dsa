// Problem   --> Check if Array is Sorted
// Platform  --> GeeksforGeeks (GFG)
// Approach  --> Linear Traversal

class Solution {
public:

    bool arraySortedOrNot(int arr[], int n) {

        // Approach -->
        // Har current element ko uske previous element se compare karege.
        // Agar kisi bhi jagah current element
        // previous element se chhota mil gaya,
        // to array sorted nahi hai.
        // Agar poora loop complete ho gaya,
        // to array sorted hai.

        // Index 1 se start karenge
        // kyunki pehle element ka koi previous element nahi hota.
        for (int i = 1; i < n; i++) {

            // Current element ko previous element se compare karo.
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }

        // Kahin bhi order break nahi hua.
        return true;
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/