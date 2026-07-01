/* ============================================================
   Lecture 04 - Type Conversion (C++)
   ============================================================ */

#include <iostream>
using namespace std;

int main() {

    // =========================================================
    // PART 1: Implicit Type Conversion (Automatic)
    // =========================================================
    // Compiler khud hi chhote type ko bade type me convert kar deta hai
    // Isme koi data loss nahi hoti

    cout << "========== Implicit Type Conversion ==========" << endl;

    // ---------------------------------------------------------
    // Example 1: int ko double me convert karna
    // ---------------------------------------------------------
    // int chhota hai, double bada hai
    // Compiler automatically int ko double bana dega

    int a = 10;
    double b = a;                           // automatic conversion
    cout << "int a = " << a << " -> double b = " << b << endl;
    // Output: int a = 10 -> double b = 10
    // Dekho: 10 ka 10.0 ban gaya, koi data loss nahi

    // ---------------------------------------------------------
    // Example 2: char ko int me convert karna
    // ---------------------------------------------------------
    // Har character ka ek ASCII value hota hai
    // 'A' ka ASCII value 65 hai

    char ch = 'A';
    int num = ch;                           // char -> int (ASCII value)
    cout << "char ch = '" << ch << "' -> int num = " << num << endl;
    // Output: char ch = 'A' -> int num = 65
    // 'A' ka ASCII code 65 hai

    // ---------------------------------------------------------
    // Example 3: int ko float me convert karna
    // ---------------------------------------------------------
    int x = 5;
    float y = x;                            // int -> float
    cout << "int x = " << x << " -> float y = " << y << endl;
    // Output: int x = 5 -> float y = 5
    // 5 ka 5.0 ban gaya

    // ---------------------------------------------------------
    // Type Hierarchy (Chhota se Bada)
    // ---------------------------------------------------------
    // char -> short -> int -> long -> float -> double
    // Left side chhota hai, right side bada hai
    // Hamesha left se right me conversion safe hai

    // ---------------------------------------------------------
    // Dangerous Implicit Conversion (Data Loss!)
    // ---------------------------------------------------------
    // Bade type ko chhote me convert karna risky hai

    cout << "\n========== Dangerous Conversions ==========" << endl;

    // Example 1: double ko int me - decimal part gayab!
    double pi = 3.14159;
    int truncated = pi;                     // decimal part lost!
    cout << "double pi = " << pi << " -> int = " << truncated << endl;
    // Output: double pi = 3.14159 -> int = 3
    // 0.14159 gayab ho gaya! ⚠️ Data Loss

    // Example 2: bada number chhote me - overflow!
    int big = 100000;
    short small = big;                      // overflow ho sakta hai
    cout << "int big = " << big << " -> short = " << small << endl;
    // Output unpredictable! short ki limit cross ho gayi

    // =========================================================
    // PART 2: Explicit Type Conversion (Type Casting)
    // =========================================================
    // Khud se manually type change karna
    // Do tareeke hain: C-Style aur C++ Style

    cout << "\n========== Explicit Type Conversion ==========" << endl;

    // ---------------------------------------------------------
    // Method 1: C-Style Cast (type)variable
    // ---------------------------------------------------------
    double value = 3.14159;
    int casted = (int)value;                // C-style cast
    cout << "(int)" << value << " = " << casted << endl;
    // Output: (int)3.14159 = 3

    // ---------------------------------------------------------
    // Method 2: C++ Style Cast - static_cast<type>(variable)
    // ---------------------------------------------------------
    // Ye zyada safe aur readable hai
    int cppCasted = static_cast<int>(value);
    cout << "static_cast<int>(" << value << ") = " << cppCasted << endl;
    // Output: static_cast<int>(3.14159) = 3

    // =========================================================
    // Real World Examples - Kyun Casting Zaroori Hai?
    // =========================================================

    cout << "\n========== Real World Examples ==========" << endl;

    // ---------------------------------------------------------
    // Example 1: Division Problem
    // ---------------------------------------------------------
    // int/int = int (decimal part kat jaati hai!)

    int p = 10, q = 3;
    cout << "\nWithout cast: " << p << "/" << q << " = " << p/q << endl;
    // Output: Without cast: 10/3 = 3 (galat!)
    // Kyunki dono int hain, result bhi int hoga

    // Fix: Ek ko double bana do
    cout << "With cast: (double)" << p << "/" << q << " = " << (double)p/q << endl;
    // Output: With cast: (double)10/3 = 3.33333 (sahi!)
    // Pehle p ko double banaya, ab result double hoga

    // ---------------------------------------------------------
    // Example 2: Percentage Calculation
    // ---------------------------------------------------------
    int marks = 85;
    int total = 100;

    // ❌ Galat tareeka
    int wrongPercent = (marks / total) * 100;
    cout << "\nWrong: (" << marks << "/" << total << ") * 100 = " << wrongPercent << endl;
    // Output: Wrong: (85/100) * 100 = 0
    // 85/100 = 0 (integer division), 0*100 = 0 😱

    // ✅ Sahi tareeka
    double correctPercent = ((double)marks / total) * 100;
    cout << "Correct: ((double)" << marks << "/" << total << ") * 100 = " << correctPercent << endl;
    // Output: Correct: ((double)85/100) * 100 = 85

    // ---------------------------------------------------------
    // Example 3: Average Calculation
    // ---------------------------------------------------------
    int m1 = 10, m2 = 20, m3 = 30;

    // ❌ Galat - decimal part gayab
    int wrongAvg = (m1 + m2 + m3) / 3;
    cout << "\nWrong average: (" << m1 << "+" << m2 << "+" << m3 << ")/3 = " << wrongAvg << endl;
    // Output: Wrong average: (10+20+30)/3 = 20

    // ✅ Sahi - pehle sum ko double banao
    double correctAvg = (double)(m1 + m2 + m3) / 3;
    cout << "Correct average: (double)(" << m1 << "+" << m2 << "+" << m3 << ")/3 = " << correctAvg << endl;
    // Output: Correct average: (double)(10+20+30)/3 = 20

    // ---------------------------------------------------------
    // Type Conversion Rules in Expressions
    // ---------------------------------------------------------
    // Result ka type = expression me sabse bada type
    // int + int = int
    // int + double = double
    // float + double = double
    // char + int = int

    cout << "\n========== Expression Rules ==========" << endl;
    int aa = 10;
    double bb = 3.5;
    auto result = aa + bb;                  // auto = compiler khud type decide karega
    cout << aa << " + " << bb << " = " << result << " (type: double)" << endl;
    // Output: 10 + 3.5 = 13.5 (type: double)

    int xx = 5, yy = 2;
    double zz = xx / yy;                    // pehle int division, phir double me store
    cout << xx << "/" << yy << " stored in double = " << zz << endl;
    // Output: 5/2 stored in double = 2 (NOT 2.5!)
    // Pehle 5/2 = 2 (int), phir 2 ko double me 2.0 banaya

    return 0;
}