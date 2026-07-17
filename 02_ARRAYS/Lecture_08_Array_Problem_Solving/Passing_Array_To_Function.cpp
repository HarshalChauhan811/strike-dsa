#include <iostream>
using namespace std;

/*
==========================================
Passing Array to Function in C++
==========================================

Problem Statement
------------------------------------------
Understand how an array is passed to a function in C++.

Example

Input:
arr = [10,20,30,40,50]

Output:
10 20 30 40 50
100

Reason:
Function ke andar arr[0] = 100 kiya gaya.
Array ka base address pass hota hai, isliye original array modify ho gaya.

------------------------------------------
Approach
------------------------------------------
• Array function me pass hone par uska base address pass hota hai.
• Function original memory par kaam karta hai.
• Isliye changes original array me reflect hote hain.

Algorithm
------------------------------------------
1. Array create karo.
2. Function me pass karo.
3. Elements print karo.
4. First element modify karo.
5. Updated value print karo.

Time Complexity : O(n)
Space Complexity: O(1)
*/

void printValue(int arr[], int n) {

    // Array print karo
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    // Original array modify hoga
    arr[0] = 100;
}

int main() {

    int arr[5] = {10, 20, 30, 40, 50};

    // Function Call
    printValue(arr, 5);

    // Change reflect hoga
    cout << arr[0] << endl;

    return 0;
}

/*
------------------------------------------
Output
------------------------------------------
10 20 30 40 50
100

------------------------------------------
Summary
------------------------------------------
Concept          : Passing Array to Function
Time Complexity  : O(n)
Space Complexity : O(1)

✔ Array ka base address pass hota hai.
✔ Original array modify hota hai.
✔ Array Pass by Reference jaisa behave karta hai.
*/