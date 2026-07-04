int missingNumber(int arr[], int n) {

    int size = n + 1;

    // 1 se size tak check karo
    for (int i = 1; i <= size; i++) {

        bool found = false;

        // Current number ko array me search karo
        for (int j = 0; j < n; j++) {

            if (arr[j] == i) {
                found = true;
                break;
            }
        }

        // Agar number nahi mila
        // wahi missing number hai
        if (!found) {
            return i;
        }
    }

    return -1;
}



// Approach 2 

int missingNumber(int arr[], int n) {

    int size = n + 1;

    // Expected Sum
    int expectedSum = size * (size + 1) / 2;

    // Array ka Actual Sum
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    // Difference hi missing number hai
    return expectedSum - actualSum;
}



// Approach 3 


int missingNumberXOR(int arr[], int n) {

    int size = n + 1;

    int ans = 0;

    // 1 se size tak XOR karo
    for (int i = 1; i <= size; i++) {
        ans ^= i;
    }

    // Array ke saare elements XOR karo
    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }

    return ans;
}