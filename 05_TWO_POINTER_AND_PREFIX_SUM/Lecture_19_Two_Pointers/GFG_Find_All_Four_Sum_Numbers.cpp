#include <vector>
#include <algorithm>
using namespace std;

/*
====================================================
            4 Sum - Find Four Elements
====================================================

Problem
----------------------------------------------------
Given an integer array `arr` and an integer `target`,
determine whether there exist four distinct elements
whose sum is equal to the target.

Return:
• true  -> Quadruplet exists.
• false -> No such quadruplet exists.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : arr = [1,4,45,6,10,12], target = 22
Output: true

Quadruplet:
1 + 4 + 7 + 10 = 22 (Example)

----------------------------------------------------

Example 2
Input : arr = [1,2,3,4]
target = 100

Output: false

----------------------------------------------------

Example 3 (Edge Case)
Input : arr = [2,2,2,2]
target = 8

Output: true

----------------------------------------------------
Approach 1 : Brute Force
----------------------------------------------------
Generate every possible quadruplet.

Check whether

arr[i] + arr[j] + arr[k] + arr[l] == target

If yes,
return true.

----------------------------------------------------
Time Complexity
----------------------------------------------------
O(n⁴)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

====================================================
              APPROACH 1 (Brute Force)
====================================================
*/

bool find4Numbers(vector<int>& arr, int target) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                for (int l = k + 1; l < n; l++) {

                    if (arr[i] + arr[j] + arr[k] + arr[l] == target)
                        return true;
                }
            }
        }
    }

    return false;
}

/*
====================================================
      APPROACH 2 (Sorting + Two Pointers)
====================================================

Approach
----------------------------------------------------
1. Sort the array.
2. Fix the first two elements.
3. Find the remaining two elements using
   Two Pointers.

newTarget = target - first - second

----------------------------------------------------
Time Complexity
----------------------------------------------------
Sorting      : O(n log n)

Nested Loops : O(n²)

Two Pointers : O(n)

Overall      : O(n³)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
✔ Sorting
✔ Two Pointers
✔ 4 Sum

====================================================
*/

bool find4Numbers(vector<int>& arr, int target) {

    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n - 3; i++) {

        for (int j = i + 1; j < n - 2; j++) {

            int left = j + 1;
            int right = n - 1;

            int newTarget = target - arr[i] - arr[j];

            while (left < right) {

                int sum = arr[left] + arr[right];

                // Quadruplet Found
                if (sum == newTarget) {
                    return true;
                }

                // Need Bigger Sum
                else if (sum < newTarget) {
                    left++;
                }

                // Need Smaller Sum
                else {
                    right--;
                }
            }
        }
    }

    return false;
}

/*
====================================================
                  SHORT DRY RUN
====================================================

Input

arr = [1,4,45,6,10,12]

target = 22

----------------------------------------------------

After Sorting

arr = [1,4,6,10,12,45]

----------------------------------------------------

i = 0
j = 1

newTarget = 22 - 1 - 4 = 17

left = 2
right = 5

6 + 45 = 51

Too Large

right--

------------------------

6 + 12 = 18

Too Large

right--

------------------------

6 + 10 = 16

Too Small

left++

left == right

No Pair Found

----------------------------------------------------

Remaining iterations continue similarly.

If any pair equals newTarget,
return true.

Otherwise,
return false.

====================================================
Interview Takeaways
====================================================

✔ Brute Force checks every possible quadruplet.

✔ Sorting + Two Pointers reduces the complexity
  from O(n⁴) to O(n³).

✔ This is the standard interview approach for
  the 4 Sum existence problem.

====================================================