#include <bits/stdc++.h>
using namespace std;

/*
====================================================
       LeetCode 410 - Split Array Largest Sum
====================================================

Problem Statement
----------------------------------------------------
Given an integer array nums and an integer k.

Split the array into exactly k
non-empty continuous subarrays.

Return the minimum possible value
of the largest subarray sum.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:

nums = [7,2,5,10,8]
k = 2

Output:

18

Reason:

Split:

[7,2,5]  [10,8]

Largest Sum = 18

----------------------------------------------------

Example 2

Input:

nums = [1,2,3,4,5]
k = 2

Output:

9

Reason:

Split:

[1,2,3]  [4,5]

Largest Sum = 9

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search on Answer

Idea:

Hum array ko search nahi kar rahe.

Hum Largest Subarray Sum
search kar rahe hain.

Har guessed answer ke liye
check karenge ki

k ya usse kam partitions me
array split ho sakta hai ya nahi.

Agar possible hai,

to aur chhota answer try karenge.

----------------------------------------------------
Algorithm
----------------------------------------------------

1. Search Space

      start = Largest Element

      end = Total Sum

2. Middle sum nikalo.

3. Agar split possible hai

      Answer store karo.

      Left side search karo.

4. Nahi to

      Right side search karo.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------

Jaise-jaise

Maximum Allowed Sum

badhega,

array ko split karna
aur aasaan hota jayega.

Maximum Sum ↑

Split Easier

↓

Monotonic Property

↓

Binary Search

----------------------------------------------------
Time Complexity
----------------------------------------------------

Possible Function

O(n)

Binary Search

O(log(Sum))

Total

O(n × log(Sum))

----------------------------------------------------
Space Complexity
----------------------------------------------------

O(1)

----------------------------------------------------
Pattern
----------------------------------------------------

Binary Search

Answer Search

Greedy Partition
*/

class Solution {
public:

    // Check karo ki given maxSum ke andar
    // array ko k ya usse kam partitions
    // me split kar sakte hain ya nahi.
    bool possible(vector<int>& nums, int k, int maxSum) {

        // Pehla partition already present hai.
        int partitions = 1;

        // Current partition ka sum.
        int currentSum = 0;

        for (int num : nums) {

            // Agar current element add karne ke baad
            // maxSum exceed nahi hota,
            // to isi partition me add kar do.
            if (currentSum + num <= maxSum) {

                currentSum += num;
            }

            // Sum exceed ho gaya.
            // Naya partition banao.
            else {

                partitions++;
                currentSum = num;
            }
        }

        // Agar required partitions
        // k se kam ya equal hain,
        // to ye maxSum possible hai.
        return partitions <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        // Minimum possible answer
        // largest element jitna hoga.
        int start = *max_element(nums.begin(), nums.end());

        // Maximum possible answer
        // poore array ke sum ke equal hoga.
        int end = accumulate(nums.begin(), nums.end(), 0);

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Agar ye maxSum possible hai,
            // to aur chhota answer try karo.
            if (possible(nums, k, mid)) {

                answer = mid;
                end = mid - 1;
            }

            // maxSum kam hai,
            // isliye badhao.
            else {

                start = mid + 1;
            }
        }

        return answer;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------

Algorithm        : Binary Search on Answer

LeetCode Problem : 410 - Split Array Largest Sum

Time Complexity  : O(n × log(Sum))

Space Complexity : O(1)

Concepts Used:

✔ Binary Search

✔ Answer Search

✔ Greedy Partition

✔ Monotonic Property
*/