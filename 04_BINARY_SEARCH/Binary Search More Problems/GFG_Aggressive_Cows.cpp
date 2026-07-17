#include <bits/stdc++.h>
using namespace std;

/*
====================================================
            Aggressive Cows (GFG / SPOJ)
====================================================

Problem Statement
----------------------------------------------------
Given the positions of stalls and the number
of cows.

Place all cows in the stalls such that
the minimum distance between any two cows
is as large as possible.

Return the largest possible minimum distance.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:

stalls = [1,2,4,8,9]
cows = 3

Output:

3

Reason:

Cow 1 -> 1

Cow 2 -> 4

Cow 3 -> 8

Minimum Distance = 3

----------------------------------------------------

Example 2

Input:

stalls = [1,2,3,4,5]
cows = 3

Output:

2

Reason:

Cow 1 -> 1

Cow 2 -> 3

Cow 3 -> 5

Minimum Distance = 2

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search on Answer

Idea:

Hum stalls search nahi kar rahe.

Hum minimum distance search
kar rahe hain.

Har guessed distance ke liye
check karenge ki

kya saari cows ko
itni minimum distance ke saath
place kar sakte hain ya nahi.

Agar possible hai,

to aur badi distance try karenge.

----------------------------------------------------
Algorithm
----------------------------------------------------

1. Stalls ko sort karo.

2. Search Space

   start = 1

   end = lastStall - firstStall

3. Middle distance nikalo.

4. Agar placement possible hai

      Answer store karo.

      Right side search karo.

5. Nahi to

      Left side search karo.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------

Jaise-jaise

Minimum Required Distance

badhegi,

cows ko place karna
aur mushkil hota jayega.

Distance ↑

Placement ↓

Ye ek

Monotonic Property

hai.

Isliye

Binary Search on Answer

lag sakti hai.

----------------------------------------------------
Time Complexity
----------------------------------------------------

Sorting

O(n log n)

Binary Search

O(log(MaxDistance))

Possible Function

O(n)

Total

O(n log n + n log(MaxDistance))

----------------------------------------------------
Space Complexity
----------------------------------------------------

O(1)

----------------------------------------------------
Pattern
----------------------------------------------------

Binary Search

Answer Search

Greedy Placement
*/

class Solution {
public:

    // Check karta hai ki given minimum distance par
    // hum saari cows ko place kar sakte hain ya nahi.
    bool possible(vector<int>& stalls, int cows, int distance) {

        // Pehli cow hamesha first stall me rakhte hain.
        int placed = 1;

        // Last placed cow ki position.
        int lastPosition = stalls[0];

        // Baaki stalls check karo.
        for (int i = 1; i < stalls.size(); i++) {

            // Agar current stall
            // required distance maintain kar raha hai,
            // to yaha cow place kar do.
            if (stalls[i] - lastPosition >= distance) {

                placed++;
                lastPosition = stalls[i];
            }
        }

        // Agar saari cows place ho gayi,
        // to ye distance possible hai.
        return placed >= cows;
    }

    int aggressiveCows(vector<int>& stalls, int cows) {

        // Binary Search ke liye sorting zaruri hai.
        sort(stalls.begin(), stalls.end());

        // Minimum possible distance.
        int start = 1;

        // Maximum possible distance.
        int end = stalls.back() - stalls.front();

        int answer = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Agar ye distance possible hai,
            // to aur badi distance try karo.
            if (possible(stalls, cows, mid)) {

                answer = mid;
                start = mid + 1;
            }

            // Distance bahut badi hai.
            // Isliye kam distance try karo.
            else {

                end = mid - 1;
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

Problem          : Aggressive Cows

Time Complexity  : O(n log n + n log(MaxDistance))

Space Complexity : O(1)

Concepts Used:

✔ Binary Search

✔ Answer Search

✔ Greedy Placement

✔ Monotonic Property
*/