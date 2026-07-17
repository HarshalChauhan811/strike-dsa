#include <bits/stdc++.h>
using namespace std;

/*
====================================================
          LeetCode 268 - Missing Number
====================================================

Problem Statement
----------------------------------------------------
Given an array nums containing n distinct
numbers in the range [0, n].

Return the only number that is missing
from the array.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
nums = [3,0,1]

Output:
2

Reason:
Range [0,3] me numbers
0,1,2,3 hone chahiye.
2 missing hai.

--------------------------

Example 2

Input:
nums = [0,1]

Output:
2

Reason:
Range [0,2] me
sirf 2 missing hai.

--------------------------

Example 3

Input:
nums = [9,6,4,2,3,5,7,0,1]

Output:
8

Reason:
0 se 9 tak
sirf 8 missing hai.

--------------------------

Example 4

Input:
nums = [0]

Output:
1

Reason:
Range [0,1] me
1 missing hai.
*/


// =====================================================
// Approach 1 : Brute Force
// =====================================================

/*
Approach
----------------------------------------------------
• 0 se n tak har expected number check karo.
• Har expected number ko poore array me search karo.
• Jo number array me nahi milega,
  wahi missing number hoga.

Algorithm
----------------------------------------------------
1. n = array size.
2. Loop 0 se n tak chalao.
3. Har number ko poore array me search karo.
4. Agar number na mile,
   wahi answer return kar do.
5. Agar sab mil jaye,
   return -1.

Time Complexity  : O(n²)

Space Complexity : O(1)
*/

class Solution {
public:

    int missingNumber(vector<int>& arr) {

        // Array ka size.
        int n = arr.size();

        // 0 se n tak
        // saare expected numbers check karo.
        for (int i = 0; i <= n; i++) {

            // Maan lo abhi
            // ye number nahi mila.
            bool found = false;

            // Current expected number ko
            // poore array me search karo.
            for (int j = 0; j < n; j++) {

                // Number mil gaya.
                if (arr[j] == i) {

                    found = true;
                    break;
                }
            }

            // Agar number nahi mila,
            // wahi missing number hai.
            if (!found)
                return i;
        }

        // Valid input me
        // ye execute nahi hoga.
        return -1;
    }
};


/*
// =====================================================
// Approach 2 : Sum Formula
// =====================================================

Approach
----------------------------------------------------
• Array ke saare elements ka Actual Sum nikalo.
• 0 se n tak numbers ka Expected Sum nikalo.
• Dono sums ka difference hi
  missing number hoga.

Formula
----------------------------------------------------
Expected Sum = n × (n + 1) / 2

Algorithm
----------------------------------------------------
1. Array ka Actual Sum calculate karo.
2. Formula se Expected Sum nikalo.
3. Expected Sum - Actual Sum return karo.

Time Complexity  : O(n)

Space Complexity : O(1)
*/

class Solution {
public:

    int missingNumber(vector<int>& arr) {

        int n = arr.size();

        int actualSum = 0;

        // Array ka Actual Sum calculate karo.
        for (int i = 0; i < n; i++) {

            actualSum += arr[i];
        }

        // Expected Sum (0 se n tak).
        int expectedSum = n * (n + 1) / 2;

        // Difference hi missing number hai.
        return expectedSum - actualSum;
    }
};


/*
// =====================================================
// Approach 3 : XOR (Optimal)
// =====================================================

Approach
----------------------------------------------------
• Expected Numbers (0 se n) ka XOR karo.
• Array ke Actual Numbers ka XOR karo.
• Same numbers ek dusre ko cancel kar denge.
• Jo number bachega wahi missing number hoga.

Example
----------------------------------------------------
nums = [3,0,1]

Expected:
0 ^ 1 ^ 2 ^ 3

Actual:
3 ^ 0 ^ 1

Common numbers cancel ho jayenge.

Bachega:

2

Algorithm
----------------------------------------------------
1. ans = n se initialize karo.
2. Loop 0 se n-1 tak chalao.
3. ans ^= i
4. ans ^= arr[i]
5. ans return karo.

Time Complexity  : O(n)

Space Complexity : O(1)
*/

class Solution {
public:

    int missingNumber(vector<int>& arr) {

        int n = arr.size();

        // n ko pehle include kar diya,
        // taki expected range 0 se n
        // complete cover ho jaye.
        int ans = n;

        // Ek hi loop me
        // Expected Numbers aur
        // Actual Numbers ka XOR.
        for (int i = 0; i < n; i++) {

            // Expected Number.
            ans ^= i;

            // Actual Number.
            ans ^= arr[i];
        }

        // Sirf missing number bachega.
        return ans;
    }
};

/*
====================================================
Summary
====================================================

Approach 1
------------------------------------------
Algorithm        : Brute Force

Time Complexity  : O(n²)

Space Complexity : O(1)

--------------------------

Approach 2
------------------------------------------
Algorithm        : Sum Formula

Time Complexity  : O(n)

Space Complexity : O(1)

--------------------------

Approach 3 (Optimal)
------------------------------------------
Algorithm        : XOR

Time Complexity  : O(n)

Space Complexity : O(1)

----------------------------------------------------
Concepts Used
----------------------------------------------------

✔ Array Traversal

✔ Linear Search

✔ Mathematics (Sum Formula)

✔ Bit Manipulation (XOR)

✔ XOR Cancellation Property




/*
====================================================
Dry Run
====================================================

Approach 1 : Brute Force

nums = [3,0,1], n = 3

i = 0 → Check array → 0 found ✓
i = 1 → Check array → 1 found ✓
i = 2 → Check array → Not found ✗

Missing Number = 2

----------------------------------------------------

Approach 2 : Sum Formula

nums = [3,0,1]

Expected Sum = 0+1+2+3 = 6
Actual Sum   = 3+0+1 = 4

Missing Number = Expected - Actual
               = 6 - 4
               = 2

----------------------------------------------------

Approach 3 : XOR

nums = [3,0,1], n = 3

Initial ans = 3

i = 0 → ans = 3 ^ 0 ^ 3 = 0
i = 1 → ans = 0 ^ 1 ^ 0 = 1
i = 2 → ans = 1 ^ 2 ^ 1 = 2

Final ans = 2

Reason:
0^0=0, x^x=0, x^0=x

Common numbers cancel ho jate hain,
sirf missing number bach jata hai.
*/

