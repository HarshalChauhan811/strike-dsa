#include <bits/stdc++.h>
using namespace std;

/*
====================================================
          LeetCode 875 - Koko Eating Bananas
====================================================

Problem Statement
----------------------------------------------------
Koko ko bananas khana bahut pasand hai.

Har pile me kuch bananas diye hue hain.

Koko apni eating speed decide kar sakti hai
(speed = kitne bananas per hour).

Har hour:
- Koko sirf ek pile choose karti hai.
- Maximum speed jitne bananas hi kha sakti hai.
- Agar pile me bananas kam hain,
  to us pile ko finish karke
  next hour dusri pile par jayegi.

Minimum speed return karo
jisse Koko h hours ke andar
saare bananas finish kar sake.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
piles = [3,6,7,11]
h = 8

Output:
4

Reason:

Speed = 4

3  -> 1 hour
6  -> 2 hours
7  -> 2 hours
11 -> 3 hours

Total = 8 hours

----------------------------------------------------

Example 2

Input:
piles = [30,11,23,4,20]
h = 5

Output:
30

Reason:
Har pile ko sirf 1 hour mil sakta hai.

Isliye speed
largest pile ke equal honi chahiye.

----------------------------------------------------

Example 3

Input:
piles = [30,11,23,4,20]
h = 6

Output:
23

Reason:
23 bananas/hour ki speed par
Koko exactly 6 hours me
saare bananas finish kar deti hai.

----------------------------------------------------

Example 4

Input:
piles = [1]
h = 1

Output:
1

Reason:
Sirf ek banana hai,
to minimum speed bhi 1 hi hogi.

----------------------------------------------------

Example 5

Input:
piles = [312884470]
h = 968709470

Output:
1

Reason:
Hours bahut zyada hain,
isliye minimum speed hi enough hai.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search on Answer

Idea:

- Hume answer (speed) find karni hai.

- Minimum speed = 1

- Maximum speed =
  Largest pile jitni.

Har speed ke liye check karenge
ki Koko given h hours ke andar
finish kar pa rahi hai ya nahi.

Agar possible hai,
to aur chhoti speed try karenge.

Nahi to speed badhayenge.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Search Space banao.

   start = 1

   end = Largest Pile

2. Middle speed nikalo.

3. Check karo
   ye speed possible hai ya nahi.

4. Agar possible hai:

      Answer store karo.

      Left side search karo.

5. Nahi to:

      Right side search karo.

6. Minimum possible speed return karo.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
Jaise-jaise speed badhegi,

Required hours kam hote jayenge.

Speed ↑
Hours ↓

Ye ek Monotonic Property hai.

Isi wajah se
Binary Search use kar sakte hain.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Har Binary Search level par

saari piles traverse karni padti hain.

O(n)

Aur Binary Search chalega

O(log(MaxPile))

Total:

O(n × log(MaxPile))

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

    // Check karo ki given speed par
    // Koko h hours ke andar
    // saare bananas finish kar sakti hai ya nahi.
    bool possible(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for (int bananas : piles) {

            // Ceiling Division
            // Is pile ko finish karne me
            // kitne hours lagenge
            hours += (bananas + speed - 1) / speed;
        }

        // Agar hours limit ke andar hain
        // to ye speed valid hai.
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible speed
        int start = 1;

        // Maximum speed largest pile jitni hogi
        int end = *max_element(piles.begin(), piles.end());

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Agar ye speed possible hai,
            // to aur chhoti speed try karo.
            if (possible(piles, h, mid)) {

                answer = mid;
                end = mid - 1;
            }
            else {

                // Speed kam hai,
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
LeetCode Problem : 875 - Koko Eating Bananas

Time Complexity  : O(n × log(MaxPile))
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Answer Search
✔ Monotonic Function
✔ Ceiling Division
*/