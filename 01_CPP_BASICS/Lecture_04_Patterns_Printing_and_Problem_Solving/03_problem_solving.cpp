/* ============================================================
   Lecture 04 - Problem Solving (C++)
   ============================================================ */

#include <iostream>
using namespace std;

int main() {

    // =========================================================
    // PROBLEM 1: Temperature Converter
    // =========================================================
    // Celsius ko Fahrenheit me convert karna
    // Formula: F = (C * 9/5) + 32
    // Important: 9.0/5.0 likho warna integer division hoga!

    cout << "========== Problem 1: Temperature Converter ==========" << endl;

    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // 9.0/5.0 isliye likha kyunki 9/5 = 1 hota hai (integer division)
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;

    cout << celsius << "°C = " << fahrenheit << "°F" << endl;

    /* Sample Output:
    Enter temperature in Celsius: 25
    25°C = 77°F
    */

    // =========================================================
    // PROBLEM 2: Grade Percentage Calculator
    // =========================================================
    // 3 subjects ke marks leke percentage nikalo
    // Total ko double me cast karna zaroori hai!

    cout << "\n========== Problem 2: Grade Percentage ==========" << endl;

    int subject1, subject2, subject3;
    cout << "Enter marks of 3 subjects: ";
    cin >> subject1 >> subject2 >> subject3;

    int total = subject1 + subject2 + subject3;

    // (double)total isliye kyunki total/3 integer division dega
    double percentage = (double)total / 3;

    cout << "Total: " << total << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    /* Sample Output:
    Enter marks of 3 subjects: 85 90 78
    Total: 253
    Percentage: 84.3333%
    */

    // =========================================================
    // PROBLEM 3: ASCII Value Finder
    // =========================================================
    // Koi bhi character ka ASCII code nikalo
    // Simple: char ko int me cast karo

    cout << "\n========== Problem 3: ASCII Value ==========" << endl;

    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    int ascii = (int)ch;                    // char -> int (ASCII value)

    cout << "ASCII value of '" << ch << "' is " << ascii << endl;

    /* Sample Output:
    Enter a character: A
    ASCII value of 'A' is 65

    Enter a character: a
    ASCII value of 'a' is 97
    */

    // =========================================================
    // PROBLEM 4: Prime Number Check
    // =========================================================
    // Prime number wo hota hai jo sirf 1 aur khud se divisible ho
    // Logic: 2 se num-1 tak check karo, koi divisor mila to prime nahi

    cout << "\n========== Problem 4: Prime Number Check ==========" << endl;

    int num;
    cout << "Enter the Number: ";
    cin >> num;

    // 2 se chhota number kabhi prime nahi hota (0 aur 1)
    if (num < 2) {
        cout << num << " is Not a Prime Number" << endl;
    } else {
        // 2 se leke num-1 tak har number se divide karke dekho
        bool isPrime = true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {             // agar koi divisor mila
                isPrime = false;            // prime nahi hai
                break;                      // loop se bahar niklo
            }
        }

        if (isPrime) {
            cout << num << " is a Prime Number" << endl;
        } else {
            cout << num << " is Not a Prime Number" << endl;
        }
    }

    /* Sample Output:
    Enter the Number: 17
    17 is a Prime Number

    Enter the Number: 18
    18 is Not a Prime Number
    */

    // =========================================================
    // PROBLEM 5: Sum of Digits
    // =========================================================
    // Number ke har digit ka sum nikalo
    // Logic: % 10 se last digit nikalo, / 10 se last digit hatao
    // Repeat jab tak number > 0

    cout << "\n========== Problem 5: Sum of Digits ==========" << endl;

    int number;
    cout << "Enter a number: ";
    cin >> number;

    int original = number;                  // original save kar lo
    int sum = 0;

    while (number > 0) {
        int lastDigit = number % 10;        // last digit nikalo (e.g., 123 % 10 = 3)
        sum = sum + lastDigit;              // sum me add karo
        number = number / 10;               // last digit hatao (e.g., 123 / 10 = 12)
    }

    cout << "Sum of digits of " << original << " = " << sum << endl;

    /* Example step-by-step for 12345:
    Step 1: 12345 % 10 = 5, sum = 0+5 = 5, number = 1234
    Step 2: 1234 % 10 = 4, sum = 5+4 = 9, number = 123
    Step 3: 123 % 10 = 3, sum = 9+3 = 12, number = 12
    Step 4: 12 % 10 = 2, sum = 12+2 = 14, number = 1
    Step 5: 1 % 10 = 1, sum = 14+1 = 15, number = 0 (loop end)

    Sample Output:
    Enter a number: 12345
    Sum of digits of 12345 = 15
    */

    return 0;
}