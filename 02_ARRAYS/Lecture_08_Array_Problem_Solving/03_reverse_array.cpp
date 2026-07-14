// GFG Problem --> Reverse an Array

// Approach -->
// Array ko reverse karne ke liye
// first element ko last element se,
// second element ko second last se,
// aur aise hi opposite elements ko swap karte jayenge.

class Solution {
public:

    void reverseArray(int arr[], int n) {

        // Sirf n/2 tak hi loop chalega.

        // Kyunki ek swap me 2 elements apni correct position par aa jate hai.
        // Agar n/2 ke baad bhi swap karenge,
        // to wahi elements dobara swap ho jayenge
        // aur array wapas original order me aa jayega.

        for (int i = 0; i < n / 2; i++) {

            // Current element ko
            // uske opposite element se swap karo.

            int temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
    }
};

/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/