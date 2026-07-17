#include <iostream>
using namespace std;

int main() {

    // =====================================================
    // Array
    // =====================================================

    /*
        Array ek Similar Data Type ka Collection hota hai
        jo Continuous Memory Locations me store hota hai.
    */


    // =====================================================
    // Why Array?
    // =====================================================

    // Agar 5 Students ke Marks Store Karne Ho

    int marks1 = 50;
    int marks2 = 60;
    int marks3 = 70;
    int marks4 = 80;
    int marks5 = 90;

    // Agar 100 Students ke Marks Store Karne Ho
    // To 100 Variables Banana Practical Nahi Hai.

    // Isliye Array ka Use Karte Hain.


    // =====================================================
    // Array Declaration
    // =====================================================

    int marks[5];      // Size = 5
                       // Index : 0 1 2 3 4
                       // Output : [_, _, _, _, _]


    // =====================================================
    // Array Initialization
    // =====================================================

    // Method 1 : Index Wise

    marks[0] = 50;     // Output : [50, _, _, _, _]
    marks[1] = 60;     // Output : [50, 60, _, _, _]
    marks[2] = 70;     // Output : [50, 60, 70, _, _]
    marks[3] = 80;     // Output : [50, 60, 70, 80, _]
    marks[4] = 90;     // Output : [50, 60, 70, 80, 90]


    // Method 2 : Direct Initialization

    int mark[5] = {10, 20, 30, 40, 50};
    // Output : [10, 20, 30, 40, 50]


    // Compiler Automatically Size Decide Karega

    int arr1[] = {20, 30, 40, 50, 60};
    // Output : [20, 30, 40, 50, 60]
    // Size = 5


    // =====================================================
    // 0 Based Indexing
    // =====================================================

    /*
        Array Size = n

        First Index = 0
        Last Index = n - 1
    */


    // =====================================================
    // Traversing an Array
    // =====================================================

    cout << "Array Elements : ";

    for (int i = 0; i < 5; i++) {
        cout << mark[i] << " ";
    }

    cout << endl;
    // Output : 10 20 30 40 50


    // =====================================================
    // User Input in Array
    // =====================================================

    int n;

    cout << "Tell me the Size of the Array : ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " Elements : " << endl;

    // Input

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Output

    cout << "Array Elements : ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;


    /*
    Sample Input

    5
    11 22 33 44 55

    Output

    Array Elements : 11 22 33 44 55
    */


    // =====================================================
    // Why 0 Based Indexing?
    // =====================================================

    /*
        Memory Address Formula

        Base Address + (Index × Size of Data Type)

        Example

        int arr[5];

        Base Address = 1000

        arr[0] = 1000

        arr[1] = 1004

        arr[2] = 1008

        arr[3] = 1012

        arr[4] = 1016

        Agar 1 Based Indexing Hoti
        To Formula Me (Index - 1)
        Extra Calculation Karni Padti.
    */


    // =====================================================
    // Print Memory Address
    // =====================================================

    int newArr[5] = {50, 20, 40, 54, 89};

    cout << "\nMemory Addresses\n";

    for (int i = 0; i < 5; i++) {
        cout << "Index " << i << " : " << &newArr[i] << endl;
    }

    /*
    Output

    Index 0 : 0x61ff00
    Index 1 : 0x61ff04
    Index 2 : 0x61ff08
    Index 3 : 0x61ff0c
    Index 4 : 0x61ff10

    (Address System ke According Different Ho Sakte Hain)
    */

    return 0;
}

/*
====================================================
Summary
====================================================

✔ Array Similar Data Type Ka Collection Hota Hai.

✔ Continuous Memory Location Me Store Hota Hai.

✔ Array Declaration

int arr[5];

✔ Initialization

Method 1
arr[0] = 10;

Method 2
int arr[] = {10,20,30};

✔ First Index = 0

✔ Last Index = n - 1

✔ Traversal

for(int i=0;i<n;i++)

✔ Input

cin >> arr[i];

✔ Output

cout << arr[i];

✔ Memory Address Formula

Base Address + (Index × Size of Data Type)

