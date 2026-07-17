#include <bits/stdc++.h>
using namespace std;

/*
====================================================
Problem --> Segregate 0s and 1s
====================================================

GFG : Segregate 0s and 1s

====================================================
Definition

Array me sirf 0 aur 1 diye gaye hain.

Hume saare 0 ko beginning me aur
saare 1 ko ending me arrange karna hai.

Relative order maintain karna zaroori nahi hai.

====================================================
Example 1

Input

arr = [0,1,0,1,1,0]

Output

[0,0,0,1,1,1]

----------------------------------------------------
Example 2

Input

arr = [1,1,1,0,0]

Output

[0,0,1,1,1]

----------------------------------------------------
Example 3

Input

arr = [0,0,0,1]

Output

[0,0,0,1]

====================================================
Approach 1 --> Brute Force (Using Temporary Array)

1. Ek temporary array banao.
2. Pehle saare 0 temporary array me store karo.
3. Fir saare 1 temporary array me store karo.
4. Last me temporary array ko
   original array me copy kar do.

Time Complexity  : O(n)
Space Complexity : O(n)

====================================================
*/

class Solution {
public:

    void segregate0and1(vector<int> &arr) {

        int n = arr.size();

        vector<int> temp(n);

        int index = 0;

        // Step 1 --> Store all 0s
        for (int i = 0; i < n; i++) {

            if (arr[i] == 0) {

                temp[index] = arr[i];
                index++;
            }
        }

        // Step 2 --> Store all 1s
        for (int i = 0; i < n; i++) {

            if (arr[i] == 1) {

                temp[index] = arr[i];
                index++;
            }
        }

        // Step 3 --> Copy temp into original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

/*
====================================================
Dry Run

Input

arr = [0,1,0,1,1,0]

---------------------------------
Step 1

Store 0s

temp = [0,_,_,_,_,_]

temp = [0,0,_,_,_,_]

temp = [0,0,0,_,_,_]

---------------------------------
Step 2

Store 1s

temp = [0,0,0,1,_,_]

temp = [0,0,0,1,1,_]

temp = [0,0,0,1,1,1]

---------------------------------
Step 3

Copy temp into arr

arr = [0,0,0,1,1,1]

---------------------------------

Final Output

[0,0,0,1,1,1]

====================================================
*/



#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 2 --> Counting Method

Idea

1. Pehle count karo ki array me
   kitne 0 present hain.
2. First countZero positions par
   0 fill kar do.
3. Remaining positions par
   1 fill kar do.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    void segregate0and1(vector<int> &arr) {

        int n = arr.size();

        int countZero = 0;

        // Step 1 --> Count total number of 0s
        for (int i = 0; i < n; i++) {

            if (arr[i] == 0) {
                countZero++;
            }
        }

        // Step 2 --> Fill 0s
        for (int i = 0; i < countZero; i++) {
            arr[i] = 0;
        }

        // Step 3 --> Fill 1s
        for (int i = countZero; i < n; i++) {
            arr[i] = 1;
        }
    }
};

/*
====================================================
Dry Run

Input

arr = [0,1,0,1,1,0]

---------------------------------
Step 1

Count Total 0s

0 -> count = 1

1 -> count = 1

0 -> count = 2

1 -> count = 2

1 -> count = 2

0 -> count = 3

Total 0s = 3

---------------------------------
Step 2

Fill First 3 Positions with 0

arr = [0,0,0,1,1,0]

---------------------------------
Step 3

Fill Remaining Positions with 1

arr = [0,0,0,1,1,1]

---------------------------------

Final Output

[0,0,0,1,1,1]

====================================================
*/



#include <bits/stdc++.h>
using namespace std;

/*
====================================================

Approach 3 --> Two Pointers (Optimal)

Idea

1. Left pointer ko 0 chahiye.
2. Right pointer ko 1 chahiye.
3. Agar Left already 0 par hai,
   to Left pointer ko aage badha do.
4. Agar Right already 1 par hai,
   to Right pointer ko peeche le aao.
5. Agar dono wrong position par hain,
   to swap kar do.

Time Complexity  : O(n)
Space Complexity : O(1)

====================================================
*/

class Solution {
public:

    void segregate0and1(vector<int> &arr) {

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {

            // Left already correct hai
            if (arr[left] == 0) {
                left++;
            }

            // Right already correct hai
            else if (arr[right] == 1) {
                right--;
            }

            // Dono wrong position par hain
            else {

                swap(arr[left], arr[right]);

                left++;
                right--;
            }
        }
    }
};

/*
====================================================
Dry Run

Input

arr = [0,1,1,0,1,0]

---------------------------------
Initial

Left = 0
Right = 5

Array

[0,1,1,0,1,0]

---------------------------------
Step 1

arr[left] = 0

Left++

Left = 1

---------------------------------
Step 2

arr[left] = 1
arr[right] = 0

Swap

[0,0,1,0,1,1]

Left = 2
Right = 4

---------------------------------
Step 3

arr[right] = 1

Right--

Right = 3

---------------------------------
Step 4

arr[left] = 1
arr[right] = 0

Swap

[0,0,0,1,1,1]

Left = 3
Right = 2

Loop Ends

---------------------------------

Final Output

[0,0,0,1,1,1]

====================================================
*/