// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <bits/stdc++.h>
using namespace std;

/*
====================================================
          LeetCode 278 - First Bad Version
====================================================

Problem Statement
----------------------------------------------------
Suppose you have n versions of a product.

After a certain version, every version becomes bad.

You are given an API:

    bool isBadVersion(version)

Return the first bad version.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:
n = 5
firstBadVersion = 4

Versions:
1   2   3   4   5
G   G   G   B   B

Output:
4

Reason:
Version 4 is the first bad version.
All versions after it are also bad.

----------------------------------------------------

Example 2

Input:
n = 1
firstBadVersion = 1

Versions:
1
B

Output:
1

Reason:
Only one version exists and it is bad.

----------------------------------------------------

Example 3

Input:
n = 6
firstBadVersion = 3

Versions:
1   2   3   4   5   6
G   G   B   B   B   B

Output:
3

Reason:
Version 3 is the first bad version.

----------------------------------------------------

Example 4

Input:
n = 8
firstBadVersion = 8

Versions:
1   2   3   4   5   6   7   8
G   G   G   G   G   G   G   B

Output:
8

Reason:
Only the last version is bad.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:
- Versions before the first bad version are good.
- Versions from the first bad version onwards
  are bad.
- Whenever a bad version is found,
  store it as a possible answer and continue
  searching on the left.

----------------------------------------------------
Algorithm
----------------------------------------------------
1. Search between versions 1 and n.
2. Find the middle version.
3. If it is bad:
      - Store it as the answer.
      - Search on the left.
4. Otherwise:
      - Search on the right.
5. Return the first bad version.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------
The versions are divided into two parts:

Good Versions  --->  Bad Versions

This creates a monotonic search space,
making Binary Search the optimal solution.

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

----------------------------------------------------
Pattern
----------------------------------------------------
Binary Search
Answer Search
*/

class Solution {
public:
    int firstBadVersion(int n) {

        int start = 1;
        int end = n;
        int answer = n;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Possible first bad version
            if (isBadVersion(mid)) {

                answer = mid;
                end = mid - 1;     // Search on the left side
            }
            else {

                start = mid + 1;   // Search on the right side
            }
        }

        return answer;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------
Algorithm        : Binary Search
LeetCode Problem : 278 - First Bad Version

Time Complexity  : O(log n)
Space Complexity : O(1)

Concepts Used:
✔ Binary Search
✔ Answer Search
✔ Monotonic Search Space
*/