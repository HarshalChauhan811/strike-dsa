#include<iostream>
using namespace std;

int main() {

    // ============================================
    // Problem 1: Find Highest Element in Array
    // ============================================

    int a[] = {70, 30, 40, 30, 20};

    int highest = a[0];  // pehle element ko highest maan lo

    for (int i = 0; i < 5; i++) {
        if (a[i] > highest) {
            highest = a[i];  // agar koi bada mila toh update kar do
        }
    }

    cout << "Highest Element: " << highest << endl;


    // ============================================
    // Problem 2: Search Element in Array (Linear Search)
    // ============================================

    int arr2[] = {10, 70, 56, 80, 90};

    int search = 40;
    bool found = false;  // flag banaya hai taaki baad mein check kar sake

    for (int i = 0; i < 5; i++) {
        if (arr2[i] == search) {
            cout << "Search Element is " << arr2[i] << " and index is: " << i << endl;
            found = true;
            break;  // mil gaya toh loop se bahar nikal lo
        }
    }

    // agar loop pura chal gaya aur nahi mila
    if (!found) {
        cout << "Element is not present in the Array" << endl;
    }

    return 0;
}