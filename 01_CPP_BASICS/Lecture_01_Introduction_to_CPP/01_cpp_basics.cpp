// int main() --> Program execution yaha se start hota hai.
// return 0;  --> Program successfully execute ho gaya.

// Ye program bina header file ke bhi run ho sakta hai,
// lekin compiler warning dega.

#include<iostream>   // cin aur cout C++ ka core part nahi hai.
// Ye iostream library se aate hain.
// Ye preprocessor directive hai jo iostream library ko program me include karta hai.

#include<string>     // String data type aur uske functions ke liye.

using namespace std; // Baar-baar std:: likhne se bachne ke liye use karte hain.

int main() {

    // Variable Declare Then Assign
    // int age;
    // age = 25;

    int ageY = 22;   // Variable declare aur assign ek saath.

    // Multiple Variables
    int a = 10, b = 20, c = 15;

    int x;

    // Hamesha variable ko declare karte time initialize karo.
    // Uninitialized variable me garbage value hoti hai,
    // jo unpredictable behavior cause kar sakti hai.

    // ==========================
    // Data Types
    // ==========================

    int age = 20;
    double height = 5.9;
    char grade = 'A';
    bool isStudent = true;
    string Name = "Harshal Chauhan";

    cout << "Name: " << Name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Grade: " << grade << endl;
    cout << "Student: " << isStudent << endl;

    // ==========================
    // Basic String Operations
    // ==========================

    string name = "Harshal";

    cout << name.length() << endl;   // String ki length.

    // Do strings ko combine karna (Concatenation)

    string firstName = "Harshal";
    string lastName = "Chauhan";
    string fullName = firstName + lastName;

    cout << fullName << endl;

    // Character access (0-based indexing)

    cout << name[0] << endl;
    cout << name[1] << endl;

    // Space ke saath poori string input lene ke liye getline() use karte hain.

    string fullname;
    getline(cin, fullname);

    return 0;
}

// std:: --> Scope Resolution Operator.
// Ye batata hai ki cout, cin, endl, etc.
// Standard namespace (std) ke andar define hain.