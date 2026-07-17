#include <iostream>
#include <vector>   // Vector use karne ke liye ye header file include karni padti hai.
using namespace std;

int main() {

    // =====================================================
    // Vector Declaration (Different Ways)
    // =====================================================

    vector<int> arr;                      // Output : [ ]

    vector<int> arr1(5);                  // Output : [0, 0, 0, 0, 0]

    vector<int> arr2(5, 100);             // Output : [100, 100, 100, 100, 100]

    vector<int> arr3 = {10,20,30,40,50};  // Output : [10, 20, 30, 40, 50]

    vector<int> arr4(arr3);               // Output : [10, 20, 30, 40, 50]


    // =====================================================
    // Insert Elements
    // push_back() hamesha last me element insert karta hai.
    // =====================================================

    arr.push_back(10);   // Output : [10]
    arr.push_back(20);   // Output : [10, 20]
    arr.push_back(30);   // Output : [10, 20, 30]
    arr.push_back(40);   // Output : [10, 20, 30, 40]


    // =====================================================
    // Remove Last Element
    // pop_back() sirf last element ko remove karta hai.
    // =====================================================

    arr.pop_back();      // Output : [10, 20, 30]


    // =====================================================
    // Vector Size
    // =====================================================

    cout << "Size : " << arr.size() << endl;      // Output : 3


    // =====================================================
    // Print Vector Elements
    // =====================================================

    cout << "Elements : ";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;                                 // Output : 10 20 30


    // =====================================================
    // First & Last Element
    // =====================================================

    cout << "First Element : " << arr.front() << endl;   // Output : 10

    cout << "Last Element  : " << arr.back() << endl;    // Output : 30


    // =====================================================
    // Check Vector is Empty or Not
    // =====================================================

    if (arr.empty()) {
        cout << "Vector is Empty" << endl;
    }
    else {
        cout << "Vector is Not Empty" << endl;    // Output : Vector is Not Empty
    }

    return 0;
}

/*
====================================================
Final Output
====================================================

Size : 3
Elements : 10 20 30
First Element : 10
Last Element  : 30
Vector is Not Empty

====================================================
Summary
====================================================

✔ vector<int> arr;
  → Empty Vector

✔ vector<int> arr1(5);
  → Fixed Size Vector (Default Value = 0)

✔ vector<int> arr2(5,100);
  → Fixed Size Vector (All Values = 100)

✔ vector<int> arr3 = {10,20,30,40,50};
  → Initialize Vector with Elements

✔ vector<int> arr4(arr3);
  → Copy Constructor (Copy Another Vector)

✔ push_back()
  → Last me element insert karta hai.

✔ pop_back()
  → Last element remove karta hai.

✔ size()
  → Total elements return karta hai.

✔ front()
  → First element return karta hai.

✔ back()
  → Last element return karta hai.

✔ empty()
  → Check karta hai vector empty hai ya nahi.

