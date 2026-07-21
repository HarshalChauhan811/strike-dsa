#include <vector>
#include <algorithm>
using namespace std;

/*
====================================================
          Triplet Sum in Array (3Sum Existence)
====================================================

Problem
----------------------------------------------------
Given an integer array `arr` and an integer `target`,
determine whether there exists a triplet whose sum
is equal to the target.

Return:
• true  -> Triplet exists.
• false -> No such triplet exists.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1
Input : arr = [1,4,45,6,10,8], target = 22
Output: true

Triplet:
4 + 8 + 10 = 22

----------------------------------------------------

Example 2
Input : arr = [1,2,4,5], target = 50
Output: false

----------------------------------------------------

Example 3 (Edge Case)
Input : arr = [0,0,0], target = 0
Output: true

----------------------------------------------------
Approach 1 : Brute Force
----------------------------------------------------
Generate every possible triplet.

Check whether

arr[i] + arr[j] + arr[k] == target

If yes,
return true.

----------------------------------------------------
Time Complexity
----------------------------------------------------
O(n³)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

====================================================
              APPROACH 1 (Brute Force)
====================================================
*/

bool hasTripletSum(vector<int>& arr, int target) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                if (arr[i] + arr[j] + arr[k] == target) {
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
2. Fix one element.
3. Find the remaining two numbers using
   Two Pointers.

Current Target

newTarget = target - arr[i]

Now find two numbers whose sum equals
newTarget.

----------------------------------------------------
Time Complexity
----------------------------------------------------
Sorting : O(n log n)

Two Pointers : O(n²)

Overall : O(n²)

----------------------------------------------------
Space Complexity
----------------------------------------------------
O(1)

----------------------------------------------------
Pattern
----------------------------------------------------
✔ Sorting
✔ Two Pointers
✔ 3Sum

====================================================
*/

bool hasTripletSum(vector<int>& arr, int target) {

    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {

        int left = i + 1;
        int right = n - 1;

        int newTarget = target - arr[i];

        while (left < right) {

            int sum = arr[left] + arr[right];

            // Triplet Found
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

    return false;
}

/*
====================================================
                  SHORT DRY RUN
====================================================

Input:

arr = [1,4,45,6,10,8]

target = 22

----------------------------------------------------

After Sorting

arr = [1,4,6,8,10,45]

----------------------------------------------------

i = 0

arr[i] = 1

newTarget = 21

left = 1
right = 5

4 + 45 = 49

Too Large

right--

----------------------

4 + 10 = 14

Too Small

left++

----------------------

6 + 10 = 16

Too Small

left++

----------------------

8 + 10 = 18

Too Small

left++

No Pair Found

----------------------------------------------------

i = 1

arr[i] = 4

newTarget = 18

left = 2
right = 5

6 + 45 = 51

Too Large

right--

----------------------

6 + 10 = 16

Too Small

left++

----------------------

8 + 10 = 18

Target Found ✔

Triplet = (4,8,10)

Return true

====================================================
Interview Takeaways
====================================================

✔ Brute Force generates every possible triplet.

✔ Sorting + Two Pointers reduces the complexity
  from O(n³) to O(n²).

✔ This is one of the most common interview
  patterns for 3Sum problems.

====================================================