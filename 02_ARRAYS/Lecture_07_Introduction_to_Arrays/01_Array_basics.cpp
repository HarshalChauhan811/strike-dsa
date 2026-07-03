#include<iostream>
using namespace std;

int main(){


    // ============================================
    // Array kya hai 
    // ============================================

    // why array --> we have given a probelem statement 
    // 5 students ke marks ko store karo 

    // int marks1 = 50;
    // int marks2 = 60;
    // int marks3 = 70; 
    // int marks4 = 80;
    // int marks5 = 90;

    // ab aap 100 students ke marks ko store karo 
    // 100 variable bnane hoge yaha pe 

    // isliye aaray ka use krte hai array ek similar collection of data type hai jo continuous menorty lacation me store hota hai 


    // ============================================
    // array decalaration 
    // ============================================

    // int mark[5]; // 5 size ka array decalre kiya yaha pe 


    // ============================================
    // array initialization 
    // ============================================

    // Method 1 --> index by index 

    int marks[5];

    int marks1 = 50;   // index 0 pe 50 store hoga 
    int marks2 = 60;
    int marks3 = 70; 
    int marks4 = 80;
    int marks5 = 90;


    // Method 2 --> Direct Initialization 

    int mark[5] = {10, 20, 30, 40, 50};

    // ya phir
    // int mark[] = {20, 30, 40, 50, 60}; // yaha pe compiler khud 5 size le lega 


    // ============================================
    // array 0 based indexing ko folow krta hai 
    // agar array ka size n hai to last valid index n-1 hoga 
    // ============================================


    // traversing an array 

    for (int i = 0; i < 5; i++) {
        cout << mark[i] << endl;
    }


    // ============================================
    // array input lena and print krna 
    // ============================================

    int n;
    cout << "Tell me the Size of the array: ";
    cin >> n ; 

    int arr[n]; // user ke btaya size ka aray 

    cout << "Enter the value in the Array " << endl ;
    
    // Input loop 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Output Loop 

    for (int i = 0; i < n; i++) {
        cout << arr [i] << " " << endl;
    }


    // ============================================
    // array  me 0 based index kyu 
    // ============================================

    // array me memory address ka formula 
    // base_address + (index *size of data )
    // iska ek example le lo khud se 

    // 1 based indexing se probelm kya hoga --> ek extra calculation krna padta hai bas forumla me index-1 krna padta hai 


    // ============================================
    // memory addrass ko print krna array ke 
    // ============================================

    int newArr[5] = {50, 20, 40, 54, 89};

    for (int i = 0; i < 5; i++) {
        cout << &newArr[i] << endl;
    }  

    return 0;
}