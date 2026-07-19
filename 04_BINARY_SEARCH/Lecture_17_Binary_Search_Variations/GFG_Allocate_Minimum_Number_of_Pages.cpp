#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// GFG - Allocate Minimum Number of Pages
// Pattern    : Binary Search on Answer
// Difficulty : Hard
// Time       : O(n × log(sum))
// Space      : O(1)
// ============================================================================

/*
Problem Statement
-----------------
Given an array books[] where books[i] represents
the number of pages in the ith book.

Allocate books among students such that:

• Every student gets at least one book.
• Books are allocated in contiguous order.
• A book cannot be divided.

Return the minimum possible value of the
maximum pages assigned to any student.

If allocation is not possible,
return -1.

Examples
--------

Example 1

Input:
books = [12,34,67,90]
students = 2

Output:
113

Explanation:

Student 1:
12 + 34 + 67 = 113

Student 2:
90

Maximum pages assigned = 113


Example 2

Input:
books = [15,17,20]
students = 5

Output:
-1

Explanation:
Books are fewer than students.
Every student must receive at least one book.


Example 3

Input:
books = [10,20,30,40]
students = 2

Output:
60

Explanation:

Student 1:
10 + 20 + 30 = 60

Student 2:
40

Maximum pages = 60
*/

/*
==============================================================================
Brute Force Solution
==============================================================================

Idea
----
Try every possible value for the maximum pages.

For every value,
check whether books can be allocated
among all students.

The first valid value is the answer.

Algorithm
---------
1. Find the largest book.
2. Find the total number of pages.
3. Try every value between them.
4. Check whether allocation is possible.
5. Return the first valid answer.

Time Complexity
---------------
O(n × sum)

Space Complexity
----------------
O(1)

Why Not Brute Force?
--------------------
The search space can be very large.

Instead of checking every value,
Binary Search cuts the search space
in half after every iteration.
*/

/*
==============================================================================
Optimal Approach (Binary Search on Answer)
==============================================================================

Idea
----
We are NOT searching for a book.

We are searching for the answer.

Suppose the maximum pages allowed
for one student is X.

Can we allocate all books
without exceeding X pages?

If YES,
try a smaller answer.

If NO,
increase the page limit.

Search Space
------------
Minimum Answer

Largest Book

Maximum Answer

Sum of all Pages

Algorithm
---------
1. If students > books,
   return -1.

2. start = largest book.

3. end = total pages.

4. Find mid.

5. Check if allocation is possible.

6. If possible:
      Save answer.
      Search left.

7. Otherwise:
      Search right.

Why Binary Search Works?
------------------------
As the allowed pages increase,

allocation becomes easier.

This forms a monotonic property.

Impossible → Impossible → Possible → Possible

Binary Search finds the first
possible answer efficiently.
*/

class Solution {
public:

    bool possible(vector<int>& books, int students, long long maxPages) {

        int requiredStudents = 1;
        long long currentPages = 0;

        for (int pages : books) {

            // Give current book to the same student
            if (currentPages + pages <= maxPages) {

                currentPages += pages;
            }

            // Allocate a new student
            else {

                requiredStudents++;
                currentPages = pages;
            }
        }

        return requiredStudents <= students;
    }

    int findPages(vector<int>& books, int students) {

        int n = books.size();

        if (students > n)
            return -1;

        long long start = *max_element(books.begin(), books.end());
        long long end = accumulate(books.begin(), books.end(), 0LL);

        long long answer = end;

        while (start <= end) {

            long long mid = start + (end - start) / 2;

            // Allocation is possible
            if (possible(books, students, mid)) {

                answer = mid;
                end = mid - 1;
            }

            // Increase page limit
            else {

                start = mid + 1;
            }
        }

        return (int)answer;
    }
};

/*
==============================================================================
Complexity Analysis
==============================================================================

Possible Function
-----------------
O(n)

Binary Search
-------------
O(log(sum))

Overall Time Complexity
-----------------------
O(n × log(sum))

Space Complexity
----------------
O(1)

==============================================================================
Dry Run
==============================================================================

Input

books = [12,34,67,90]

students = 2

Search Space

start = 90

end = 203

Iteration 1
-----------

mid = 146

Allocation

12 + 34 + 67 = 113

+90 exceeds 146

Student 2 gets 90

Possible

Search Left

answer = 146

Iteration 2
-----------

mid = 117

Still Possible

Search Left

answer = 117

Iteration 3
-----------

mid = 103

Not Possible

Search Right

Iteration 4
-----------

mid = 110

Not Possible

Search Right

Iteration 5
-----------

mid = 113

Possible

Search Left

answer = 113

Loop Ends

Final Answer

113

==============================================================================
Key Takeaways
==============================================================================

• This is NOT a normal Binary Search problem.
• Binary Search is applied on the answer.
• Minimum answer = Largest book.
• Maximum answer = Sum of all pages.
• Greedy allocation checks whether a guessed answer is valid.
• Monotonic property makes Binary Search possible.

==============================================================================
Related Problems
==============================================================================

• LeetCode 410 - Split Array Largest Sum
• GFG - Painter's Partition Problem
• GFG - Book Allocation Problem
• GFG - Aggressive Cows
• LeetCode 1011 - Capacity To Ship Packages Within D Days

*/