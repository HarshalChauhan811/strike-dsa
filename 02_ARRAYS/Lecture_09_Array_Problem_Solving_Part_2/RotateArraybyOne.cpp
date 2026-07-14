// GFG: Cyclically Rotate an Array by One
// Right Rotation by 1

class Solution {
  public:
    void rotate(vector<int> &arr) {
        
        // Approach -->
        // Last element ko save kar lo.
        // Fir baaki elements ko ek position right shift karo.
        // Last me saved element ko first index par rakh do.
        
        int n = arr.size();
        int last = arr[n-1];

        // Right se shift karo
        // taki data overwrite na ho.
        for (int i = n-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }

        // Saved last element ko front me rakh do.
        arr[0] = last;
    }
};