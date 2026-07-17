#include <bits/stdc++.h>
using namespace std;

/*
====================================================
  LeetCode 744 - Find Smallest Letter Greater Than Target
====================================================

Problem Statement
----------------------------------------------------
Given a sorted array of characters letters and a
target character, return the smallest character
that is lexicographically greater than the target.

The letters wrap around.

For example:
If target = 'z', the answer is the first letter
of the array.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
letters = ['c','f','j']
target = 'a'

Output:
'c'

Reason:
'c' is the first letter greater than 'a'.

----------------------------------------------------

Example 2

Input:
letters = ['c','f','j']
target = 'c'

Output:
'f'

Reason:
The next greater letter after 'c' is 'f'.

----------------------------------------------------

Example 3

Input:
letters = ['c','f','j']
target = 'd'

Output:
'f'

Reason:
'f' is the smallest letter greater than 'd'.

----------------------------------------------------

Example 4

Input:
letters = ['c','f','j']
target = 'g'

Output:
'j'

Reason:
'j' is the next greater letter.

----------------------------------------------------

Example 5

Input:
letters = ['c','f','j']
target = 'j'

Output:
'c'

Reason:
No letter is greater than 'j',
so the answer wraps around to
the first character.

----------------------------------------------------

Example 6

Input:
letters = ['x','x','y','y']
target = 'z'

Output:
'x'

Reason:
Target is greater than every letter,
so the answer wraps around.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:
- Find the first character that is strictly
  greater than the target.
- Store every possible answer.
- Continue searching on the left to find the
  smallest valid character.
- If no such character exists,
  return the first character of the array.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Initialize:
   start = 0
   end = n - 1
   answer = 0

2. Find the middle index.

3. If letters[mid] > target:
      - Store current index.
      - Search on the left.

4. Otherwise:
      - Search on the right.

5. Return letters[answer].

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
The array is sorted.

Binary Search removes half of the search space
after every comparison.

We are searching for the first element
strictly greater than the target.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Best Case    : O(1)

Average Case : O(log n)

Worst Case   : O(log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

Reason:
Only a few extra variables are used.

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search
Upper Bound
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int start = 0;
        int end = letters.size() - 1;

        // Default answer handles the circular case
        int answer = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Possible answer found
            if (letters[mid] > target) {

                answer = mid;
                end = mid - 1;     // Search on the left side
            }
            else {

                start = mid + 1;   // Search on the right side
            }
        }

        return letters[answer];
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Binary Search (Upper Bound)
LeetCode Problem : 744 - Find Smallest Letter Greater Than Target

Time Complexity  : O(log n)
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Upper Bound
✔ Circular Search
✔ Search Space Reduction
*/