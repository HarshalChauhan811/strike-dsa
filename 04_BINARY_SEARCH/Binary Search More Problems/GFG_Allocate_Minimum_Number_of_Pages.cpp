#include <bits/stdc++.h>
using namespace std;

/*
====================================================
      GFG - Allocate Minimum Number of Pages
====================================================

Problem Statement
----------------------------------------------------
Given an array books[] where books[i]
represents the number of pages in the ith book.

Allocate books to students such that:

• Every student gets at least one book.
• Books are allocated in continuous order.
• One book cannot be divided.

Return the minimum possible value of
the maximum pages assigned to any student.

If allocation is not possible,
return -1.

----------------------------------------------------
Examples
----------------------------------------------------

Example 1

Input:

books = [12,34,67,90]
students = 2

Output:

113

Reason:

Student 1 -> 12 + 34 + 67 = 113

Student 2 -> 90

Maximum Pages = 113

----------------------------------------------------

Example 2

Input:

books = [15,17,20]
students = 5

Output:

-1

Reason:

Books sirf 3 hain,
students 5 hain.

Har student ko
kam se kam ek book chahiye.

Allocation possible nahi hai.

----------------------------------------------------
Approach
----------------------------------------------------
Binary Search on Answer

Idea:

Hum books ko search nahi kar rahe.

Hum Maximum Allowed Pages
search kar rahe hain.

Har guessed answer ke liye
check karenge ki

kya books ko given students me
allocate kar sakte hain ya nahi.

Agar possible hai,

to aur chhota answer try karenge.

----------------------------------------------------
Algorithm
----------------------------------------------------

1. Agar students > books

      Return -1

2. Search Space

      start = Largest Book

      end = Total Pages

3. Middle pages nikalo.

4. Agar allocation possible hai

      Answer store karo.

      Left side search karo.

5. Nahi to

      Right side search karo.

----------------------------------------------------
Why Binary Search?
----------------------------------------------------

Jaise-jaise

Maximum Allowed Pages

badhenge,

books allocate karna
aur aasaan hota jayega.

Pages ↑

Allocation Easier

↓

Monotonic Property

↓

Binary Search

----------------------------------------------------
Time Complexity
----------------------------------------------------

Possible Function

O(n)

Binary Search

O(log(Sum))

Total

O(n × log(Sum))

----------------------------------------------------
Space Complexity
----------------------------------------------------

O(1)

----------------------------------------------------
Pattern
----------------------------------------------------

Binary Search

Answer Search

Greedy Allocation
*/

class Solution {
public:

    // Check karo ki given page limit me
    // books allocate ho sakti hain ya nahi.
    bool possible(vector<int>& books, int students, long long maxPage) {

        // Pehla student already present hai.
        int requiredStudents = 1;

        // Current student ko
        // kitne pages allocate hue hain.
        long long currentPage = 0;

        for (int pages : books) {

            // Agar current book add karne ke baad
            // page limit exceed nahi hoti,
            // to isi student ko de do.
            if (currentPage + pages <= maxPage) {

                currentPage += pages;
            }

            // Limit exceed ho gayi.
            // Naya student allocate karo.
            else {

                requiredStudents++;

                // Naye student ko
                // current book se start karao.
                currentPage = pages;
            }
        }

        // Agar required students
        // available students se
        // kam ya equal hain,
        // to allocation possible hai.
        return requiredStudents <= students;
    }

    int findPages(vector<int>& books, int students) {

        int n = books.size();

        // Har student ko
        // kam se kam ek book milni chahiye.
        if (students > n)
            return -1;

        // Minimum possible answer
        long long start = *max_element(books.begin(), books.end());

        // Maximum possible answer
        long long end = accumulate(books.begin(), books.end(), 0LL);

        long long answer = end;

        while (start <= end) {

            long long mid = start + (end - start) / 2;

            // Agar allocation possible hai,
            // to aur minimum answer try karo.
            if (possible(books, students, mid)) {

                answer = mid;
                end = mid - 1;
            }

            // Page limit kam hai,
            // isliye badhao.
            else {

                start = mid + 1;
            }
        }

        return (int)answer;
    }
};

/*
----------------------------------------------------
Summary
----------------------------------------------------

Algorithm        : Binary Search on Answer

Problem          : Allocate Minimum Number of Pages

Time Complexity  : O(n × log(Sum))

Space Complexity : O(1)

Concepts Used:

✔ Binary Search

✔ Answer Search

✔ Greedy Allocation

✔ Monotonic Property
*/