#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
====================================================
           Pair with Given Difference
====================================================

Problem
----------------------------------------------------
Given an integer array `arr` and an integer `diff`,
determine whether there exists a pair whose absolute
difference is equal to `diff`.

Return:
• 1 -> Pair exists.
• 0 -> Pair doesn't exist.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : arr = [5,20,3,2,50,80], diff = 78
Output: 1

Pair:
80 - 2 = 78

----------------------------------------------------

Example 2
Input : arr = [90,70,20,80,50], diff = 45
Output: 0

----------------------------------------------------

Example 3 (Edge Case)
Input : arr = [1,1], diff = 0
Output: 1

----------------------------------------------------
Approach 1 : Brute Force
----------------------------------------------------
Check every possible pair.

If

|arr[i] - arr[j]| == diff

Return 1.

----------------------------------------------------
Time Complexity
----------------------------------------------------
O(n²)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

====================================================
              APPROACH 1 (Brute Force)
====================================================
*/

int pairWithGivenDifference(vector<int>& arr, int diff) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            if (abs(arr[i] - arr[j]) == diff) {
                return 1;
            }
        }
    }

    return 0;
}

/*
====================================================
      APPROACH 2 (Sorting + Two Pointers)
====================================================

Approach
----------------------------------------------------
1. Sort the array.
2. Maintain two pointers.

Difference = arr[end] - arr[start]

• Difference == diff
      Pair Found.

• Difference < diff
      Increase Difference.

      end++

• Difference > diff
      Decrease Difference.

      start++

----------------------------------------------------
Time Complexity
----------------------------------------------------
Sorting : O(n log n)

Traversal : O(n)

Overall : O(n log n)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
✔ Sorting
✔ Two Pointers

====================================================
*/

int pairWithGivenDifference(vector<int>& arr, int diff) {

    sort(arr.begin(), arr.end());

    int n = arr.size();

    int start = 0;
    int end = 1;

    while (end < n) {

        // Both pointers should not point
        // to the same element.
        if (start == end) {
            end++;
            continue;
        }

        int currentDiff = arr[end] - arr[start];

        // Pair Found
        if (currentDiff == diff) {
            return 1;
        }

        // Increase Difference
        else if (currentDiff < diff) {
            end++;
        }

        // Decrease Difference
        else {
            start++;
        }
    }

    return 0;
}

/*
====================================================
                  SHORT DRY RUN
====================================================

Input

arr  = [5,20,3,2,50,80]

diff = 78

----------------------------------------------------

After Sorting

arr = [2,3,5,20,50,80]

start = 0
end = 1

Difference = 3 - 2 = 1

1 < 78

Move end

----------------------------------------------------

start = 0
end = 5

Difference = 80 - 2 = 78

Pair Found ✔

Return 1

====================================================
Interview Takeaways
====================================================

✔ Brute Force checks every possible pair.

✔ Sorting enables the use of Two Pointers.

✔ Two Pointers reduces the complexity from
  O(n²) to O(n log n).

✔ Always maintain start < end while traversing.

====================================================

*/