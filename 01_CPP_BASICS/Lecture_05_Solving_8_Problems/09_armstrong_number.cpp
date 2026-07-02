#include<iostream>
using namespace std;

int main()
{
    int num, originalNum, rem, sum = 0;

    cout << "Enter a Number: ";
    cin >> num;

    originalNum = num;    // Original number ko save karna

    while (num > 0)
    {
        rem = num % 10;               // Last digit nikalna
        sum = sum + (rem * rem * rem); // Cube of each digit add karna
        num = num / 10;               // Last digit remove karna
    }

    if (sum == originalNum)
    {
        cout << originalNum << " is an Armstrong Number";
    }
    else
    {
        cout << originalNum << " is not an Armstrong Number";
    }

    return 0;
}