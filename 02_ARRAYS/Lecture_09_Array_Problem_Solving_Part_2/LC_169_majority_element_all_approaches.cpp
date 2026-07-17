#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Majority Element
====================================================

LeetCode : 169. Majority Element

====================================================
Definition

Majority Element wo element hota hai
jo array me n/2 se zyada baar aata hai.

LeetCode guarantee karta hai ki
Majority Element hamesha exist karega.

====================================================
Example 1

Input

nums = [3,2,3]

Output

3

Explanation

3 ki frequency = 2

n = 3

n / 2 = 1

2 > 1

Isliye Majority Element = 3

----------------------------------------------------
Example 2

Input

nums = [2,2,1,1,1,2,2]

Output

2

Explanation

2 ki frequency = 4

n = 7

n / 2 = 3

4 > 3

Isliye Majority Element = 2

----------------------------------------------------
Example 3

Input

nums = [5]

Output

5

Explanation

Single element hi Majority Element hai.

====================================================
Approach 1 --> Brute Force

1. Har element ki frequency
   poore array me count karo.
2. Agar frequency n/2 se zyada ho,
   wahi Majority Element hoga.

Time Complexity  : O(n²)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Har element ki frequency count karo
        for (int i = 0; i < n; i++) {

            int freq = 0;

            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j]) {
                    freq++;
                }
            }

            // Majority Element mil gaya
            if (freq > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

/*
====================================================
Dry Run

Input

nums = [2,2,1,1,1,2,2]

n = 7

Need Frequency > 3

---------------------------------
i = 0

Element = 2

Frequency = 4

4 > 3

Return 2

---------------------------------

Final Answer

2

====================================================
*/


#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 2 --> Hashing

Idea

1. Pehle har element ki frequency
   Hash Map me store karo.
2. Fir dobara array traverse karo.
3. Jis element ki frequency n/2 se
   zyada hogi,
   wahi Majority Element hoga.

Time Complexity  : O(n)
Space Complexity : O(n)

====================================================
*/

class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;

        // Step 1 --> Frequency Count
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 2 --> Find Majority Element
        for (int i = 0; i < n; i++) {

            if (freq[nums[i]] > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

/*
====================================================
Dry Run

Input

nums = [2,2,1,1,1,2,2]

n = 7

Need Frequency > 3

---------------------------------
Step 1

Frequency Map

2 -> 4

1 -> 3

---------------------------------
Step 2

nums[0] = 2

Frequency = 4

4 > 3

Return 2

---------------------------------

Final Answer

2

====================================================
*/



#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 3 --> Moore's Voting Algorithm (Optimal)

Idea

1. Candidate aur Count maintain karo.
2. Agar Count == 0 ho,
   to current element ko naya Candidate bana do.
3. Agar current element Candidate ke equal ho,
   to Count badha do.
4. Warna Count ghata do.
5. End me Candidate hi Majority Element hoga.

Why It Works?

Majority Element ki frequency
n/2 se zyada hoti hai.

Isliye baaki sabhi elements uske votes
completely cancel nahi kar sakte.

End me Majority Element hi Candidate bachta hai.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        // Traverse Complete Array
        for (int i = 0; i < nums.size(); i++) {

            // Count 0 hai to
            // naya candidate choose karo.
            if (count == 0) {
                candidate = nums[i];
            }

            // Same candidate mila
            if (nums[i] == candidate) {
                count++;
            }

            // Different candidate mila
            else {
                count--;
            }
        }

        return candidate;
    }
};

/*
====================================================
Dry Run

Input

nums = [2,2,1,1,1,2,2]

---------------------------------
Initial

Candidate = -
Count = 0

---------------------------------
Element = 2

Count = 0

Candidate = 2

Same Candidate

Count = 1

---------------------------------
Element = 2

Same Candidate

Count = 2

---------------------------------
Element = 1

Different Element

Count = 1

---------------------------------
Element = 1

Different Element

Count = 0

---------------------------------
Element = 1

Count = 0

Candidate = 1

Same Candidate

Count = 1

---------------------------------
Element = 2

Different Element

Count = 0

---------------------------------
Element = 2

Count = 0

Candidate = 2

Same Candidate

Count = 1

---------------------------------

Final Candidate

2

Final Answer

2

====================================================
*/