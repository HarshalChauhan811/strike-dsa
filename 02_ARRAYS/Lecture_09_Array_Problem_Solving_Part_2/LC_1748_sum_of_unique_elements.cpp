#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Sum of Unique Elements
====================================================

LeetCode : 1748. Sum of Unique Elements

====================================================
Definition

Array me jo elements sirf ek baar aate hain,
un sabka sum return karna hai.

====================================================
Example 1

Input

nums = [1,2,3,2]

Output

4

Explanation

Unique Elements = 1, 3

Sum = 1 + 3 = 4

----------------------------------------------------
Example 2

Input

nums = [1,1,1,1,1]

Output

0

Explanation

Koi bhi unique element nahi hai.

----------------------------------------------------
Example 3

Input

nums = [1,2,3,4,5]

Output

15

Explanation

Sabhi elements unique hain.

====================================================
Approach 1 --> Brute Force

1. Har element ki frequency poore array me count karo.
2. Agar frequency 1 ho,
   to us element ko answer me add kar do.

Time Complexity  : O(n²)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    int sumOfUnique(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        // Har element ke liye
        // frequency count karo.
        for (int i = 0; i < n; i++) {

            int freq = 0;

            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j]) {
                    freq++;
                }
            }

            // Sirf unique element add karo
            if (freq == 1) {
                sum += nums[i];
            }
        }

        return sum;
    }
};

/*
====================================================
Dry Run

Input

nums = [1,2,3,2]

---------------------------------

1 -> Frequency = 1

Sum = 1

---------------------------------

2 -> Frequency = 2

Ignore

---------------------------------

3 -> Frequency = 1

Sum = 4

---------------------------------

2 -> Frequency = 2

Ignore

---------------------------------

Final Answer

4

====================================================
*/



#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 2 --> Hashing (Frequency Array)

Idea

1. Pehle har element ki frequency store kar lo.
2. Fir dobara array traverse karo.
3. Jis element ki frequency 1 ho,
   usko answer me add kar do.

Time Complexity  : O(n)
Space Complexity : O(1)

Note
LeetCode ke according
1 <= nums[i] <= 100

Isliye frequency array ka size 101 liya hai.

====================================================
*/

class Solution {
public:

    int sumOfUnique(vector<int>& nums) {

        // Frequency Array
        vector<int> freq(101, 0);

        // Frequency Count
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int sum = 0;

        // Unique Elements ka Sum
        for (int i = 0; i < nums.size(); i++) {

            if (freq[nums[i]] == 1) {
                sum += nums[i];
            }
        }

        return sum;
    }
};

/*
====================================================
Dry Run

Input

nums = [1,2,3,2]

---------------------------------
Step 1

Frequency Count

1 -> 1
2 -> 2
3 -> 1

---------------------------------
Step 2

nums[0] = 1

Frequency = 1

Sum = 1

---------------------------------

nums[1] = 2

Frequency = 2

Ignore

---------------------------------

nums[2] = 3

Frequency = 1

Sum = 4

---------------------------------

nums[3] = 2

Frequency = 2

Ignore

---------------------------------

Final Answer

4

====================================================
*/