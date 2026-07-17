#include <bits/stdc++.h>
using namespace std;

/*
====================================================
      LeetCode 1539 - Kth Missing Positive Number
====================================================

Problem Statement
----------------------------------------------------
Given a sorted array arr of positive integers
and an integer k.

Return the kth missing positive number.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:

arr = [2,3,4,7,11]
k = 5

Output:

9

Reason:

Missing Numbers:

1, 5, 6, 8, 9, ...

5th missing positive number = 9

----------------------------------------------------

Example 2

Input:

arr = [1,2,3,4]
k = 2

Output:

6

Reason:

Missing Numbers:

5, 6, ...

2nd missing positive number = 6

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:

Har index par ek expected value honi chahiye.

Expected Value = mid + 1

Agar actual value expected value se badi hai,

to beech ke kuch numbers missing hain.

Formula:

Missing Numbers = arr[mid] - (mid + 1)

Binary Search se first index
find karenge jahan

Missing Numbers >= k

----------------------------------------------------
Algorithm
----------------------------------------------------

1. Binary Search lagao.

2. Har mid par missing numbers calculate karo.

3. Agar missing < k

      Right side search karo.

4. Otherwise

      Left side search karo.

5. Final answer

      start + k

----------------------------------------------------
Why Binary Search?
----------------------------------------------------

Jaise-jaise array me
aage badhte jaoge,

missing numbers
kabhi kam nahi honge.

Missing Count

↑

Monotonic Property

↓

Binary Search

----------------------------------------------------
Time Complexity
----------------------------------------------------

O(log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------

O(1)

----------------------------------------------------
Pattern
----------------------------------------------------

Binary Search

Missing Numbers
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Mid tak kitne numbers missing hain
            int missing = arr[mid] - (mid + 1);

            // Agar missing numbers abhi bhi
            // k se kam hain,
            // to answer right side me hoga.
            if (missing < k) {

                start = mid + 1;
            }

            // Itne missing numbers mil gaye,
            // ab left side me aur chhota answer dhoondo.
            else {

                end = mid - 1;
            }
        }

        // start batata hai ki answer se pehle
        // kitne elements array me present hain.
        return start + k;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------

Algorithm        : Binary Search

LeetCode Problem : 1539 - Kth Missing Positive Number

Time Complexity  : O(log n)

Space Complexity : O(1)

Concepts Used:

✔ Binary Search

✔ Missing Numbers

✔ Monotonic Property
*/