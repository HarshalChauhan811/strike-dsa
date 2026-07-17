#include <bits/stdc++.h>
using namespace std;

/*
====================================================
 LeetCode 1011 - Capacity To Ship Packages Within D Days
====================================================

Problem Statement
----------------------------------------------------
A conveyor belt has packages that must be shipped.

The i-th package has weights[i] weight.

The packages must be shipped in the given order.

Every day:
- Load packages one by one.
- Total weight should not exceed
  the ship capacity.

Return the minimum ship capacity
required to ship all packages
within the given number of days.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
weights = [1,2,3,4,5,6,7,8,9,10]
days = 5

Output:
15

Reason:

Day 1 -> 1 + 2 + 3 + 4 + 5 = 15

Day 2 -> 6 + 7 = 13

Day 3 -> 8

Day 4 -> 9

Day 5 -> 10

Minimum possible capacity = 15

----------------------------------------------------

Example 2

Input:
weights = [3,2,2,4,1,4]
days = 3

Output:
6

Reason:

Day 1 -> 3 + 2 = 5

Day 2 -> 2 + 4 = 6

Day 3 -> 1 + 4 = 5

----------------------------------------------------

Example 3

Input:
weights = [1,2,3,1,1]
days = 4

Output:
3

Reason:

Capacity 3 par
saare packages 4 din ke andar
ship ho jate hain.

----------------------------------------------------

Example 4

Input:
weights = [5]
days = 1

Output:
5

Reason:
Sirf ek package hai,
capacity bhi 5 hi hogi.

----------------------------------------------------

Example 5

Input:
weights = [10,50,100]
days = 1

Output:
160

Reason:
Ek hi din me
saare packages ship karne hain.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search on Answer

Idea:

- Hume minimum ship capacity
  find karni hai.

- Minimum capacity
  largest package jitni hogi.

- Maximum capacity
  saare packages ke sum ke equal hogi.

Har capacity ke liye check karenge
ki packages given days ke andar
ship ho sakte hain ya nahi.

Agar possible hai,
to aur chhoti capacity try karenge.

Nahi to capacity badhayenge.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Search Space:

   start = Maximum Weight

   end = Sum of Weights

2. Middle capacity nikalo.

3. Check karo
   ye capacity possible hai ya nahi.

4. Agar possible hai:

      Answer store karo.

      Left side search karo.

5. Nahi to:

      Right side search karo.

6. Minimum capacity return karo.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
Jaise-jaise capacity badhegi,

Required days kam hote jayenge.

Capacity ↑
Days ↓

Ye ek Monotonic Property hai.

Isi wajah se
Binary Search on Answer
apply hoti hai.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Har Binary Search level par

poora array traverse hota hai.

O(n)

Binary Search chalega

O(log(Sum of Weights))

Total:

O(n × log(Sum of Weights))

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

Reason:
Koi extra memory use nahi hoti.

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search
Answer Search
Monotonic Function
*/

class Solution {
public:

    // Check karo ki given capacity par
    // saare packages given days ke andar
    // ship ho sakte hain ya nahi.
    bool possible(vector<int>& weights, int days, int capacity) {

        int currentWeight = 0;
        int requiredDays = 1;

        for (int weight : weights) {

            // Agar current package add karne se
            // capacity exceed nahi ho rahi,
            // to isi din load kar do.
            if (currentWeight + weight <= capacity) {

                currentWeight += weight;
            }
            else {

                // Capacity exceed ho gayi,
                // naya din start karo.
                requiredDays++;
                currentWeight = weight;
            }
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum capacity
        // largest package jitni hogi.
        int start = *max_element(weights.begin(), weights.end());

        // Maximum capacity
        // saare packages ke sum ke equal hogi.
        int end = accumulate(weights.begin(), weights.end(), 0);

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Agar ye capacity possible hai,
            // to aur minimum capacity try karo.
            if (possible(weights, days, mid)) {

                answer = mid;
                end = mid - 1;
            }
            else {

                // Capacity kam hai,
                // isliye badhao.
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
LeetCode Problem : 1011 - Capacity To Ship Packages Within D Days

Time Complexity  : O(n × log(Sum of Weights))
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Answer Search
✔ Monotonic Function
✔ Capacity Search
*/