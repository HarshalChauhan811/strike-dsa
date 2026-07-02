#include <iostream>
using namespace std;

// ======================================================
// Function
// ======================================================
// Function ek reusable block of code hota hai.
// DRY Principle Follow karta hai.
// DRY = Don't Repeat Yourself
// Ek baar function banao aur jitni baar chahe use karo.

// ======================================================
// Factorial Function
// ======================================================

// Kisi number ka factorial calculate karta hai.

void fact(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    cout << "Factorial = " << factorial << endl;
}

// ======================================================
// Function with Multiple Parameters
// ======================================================

// void sum(int a, int b)
// {
//     cout << a + b << endl;
// }

// ======================================================
// Return Function
// ======================================================
// Return tab use karte hain jab function ki value
// ko main() ya kisi aur function me use karna ho.

int mul(int a, int b)
{
    return a * b;
}

int square(int n)
{
    return n * n;
}

// ======================================================
// Function Overloading
// ======================================================
// Function Name Same
// Parameter Different
// Compiler parameter ke basis par decide karta hai
// kaunsa function call hoga.

int sum(int a, int b)
{
    return a + b;
}

int sum(int a, int b, int c)
{
    return a + b + c;
}

float sum(float a, float b)
{
    return a + b;
}

// ======================================================
// Call By Value
// ======================================================
// Value ki copy function me jati hai.
// Original variable change nahi hota.

void increment(int a)
{
    a++;
}

// ======================================================
// Pass By Reference
// ======================================================
// Original variable ka reference function me jata hai.
// Function ke andar jo change hoga,
// wahi original variable me bhi reflect hoga.

void PassByReference(int &n)
{
    n++;
}

// ======================================================
// Swap Two Numbers
// ======================================================
// Reference use karke original values swap hongi.

void SwapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ======================================================
// Default Parameter
// ======================================================
// Default Parameter ka matlab hota hai ki agar function
// call karte time argument pass nahi kiya,
// to function automatically default value use karega.
//
// Rule:
// Default parameter hamesha last me likhte hain.

void greet(string name = "Harshal")
{
    cout << "Hello " << name << endl;
}


// ======================================================
// Main Function
// ======================================================


int main()
{
    // ==================================================
    // Why Functions?
    // ==================================================

    // Agar 30 baar factorial nikalna ho
    // to baar-baar same code likhne ki jagah
    // sirf function call karenge.

    fact(5);

    // ==================================================
    // Return Function Example
    // ==================================================

    cout << "Multiplication = " << mul(5, 2) << endl;

    cout << "Square = " << square(5) << endl;

    // ==================================================
    // Function Overloading Example
    // ==================================================

    cout << "Sum (2 Numbers) = " << sum(2, 3) << endl;

    cout << "Sum (3 Numbers) = " << sum(2, 3, 4) << endl;

    cout << "Float Sum = " << sum(5.5f, 2.8f) << endl;

    // ==================================================
    // Call By Value
    // ==================================================

    int a = 10;

    increment(a);

    // Original Value Change Nahi Hui

    cout << "Call By Value = " << a << endl;

    // ==================================================
    // Pass By Reference
    // ==================================================

    int b = 20;

    PassByReference(b);

    // Original Value Change Ho Gayi

    cout << "Pass By Reference = " << b << endl;

    // ==================================================
    // Swap Example
    // ==================================================

    int n = 10;
    int m = 20;

    cout << "Before Swap : " << n << " " << m << endl;

    SwapNumber(n, m);

    cout << "After Swap  : " << n << " " << m << endl;

  
    // Default Parameter Example

    greet();          // Default Value Use Hogi
    greet("Rahul");   // Passed Value Use Hogi

    return 0;
}