#include <bits/stdc++.h>
using namespace std;

/*
====================================================
          LeetCode 74 - Search a 2D Matrix
====================================================

Problem Statement
----------------------------------------------------
You are given an m × n integer matrix
with the following properties:

• Each row is sorted in ascending order.
• The first integer of each row is greater
  than the last integer of the previous row.

Given an integer target,
return true if target exists in the matrix,
otherwise return false.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:

matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 3

Output:

true

Reason:

3 matrix me present hai.

----------------------------------------------------

Example 2

Input:

matrix =
[
 [1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]
]

target = 13

Output:

false

Reason:

13 matrix me present nahi hai.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search

Idea:

Puri matrix ko
ek sorted 1D array ki tarah
treat karo.

Index Mapping

mid

↓

row = mid / cols

col = mid % cols

Fir normal Binary Search
apply kar do.

----------------------------------------------------
Algorithm
----------------------------------------------------

1. Rows aur Columns count karo.

2. Search Space banao.

   start = 0

   end = rows × cols - 1

3. Har mid ko

   row aur col me convert karo.

4. Agar target mil jaye

      return true

5. Agar current value chhoti hai

      Right side search karo.

6. Warna

      Left side search karo.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------

Matrix ki har row sorted hai.

Aur

Current row ka last element

<

Next row ka first element.

Isliye

Puri matrix ko
ek sorted array ki tarah
treat kar sakte hain.

Isi wajah se

Binary Search

lag sakti hai.

----------------------------------------------------
Time Complexity
----------------------------------------------------

O(log(m × n))

----------------------------------------------------
Space Complexity
----------------------------------------------------

O(1)

----------------------------------------------------
Pattern
----------------------------------------------------

Binary Search

Matrix

Index Mapping
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows * cols - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            // 1D index ko
            // 2D index me convert karo.
            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target) {

                return true;
            }

            // Target right side me hoga.
            else if (matrix[row][col] < target) {

                start = mid + 1;
            }

            // Target left side me hoga.
            else {

                end = mid - 1;
            }
        }

        return false;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------

Algorithm        : Binary Search

LeetCode Problem : 74 - Search a 2D Matrix

Time Complexity  : O(log(m × n))

Space Complexity : O(1)

Concepts Used:

✔ Binary Search

✔ Matrix

✔ Index Mapping

✔ 1D to 2D Conversion
*/