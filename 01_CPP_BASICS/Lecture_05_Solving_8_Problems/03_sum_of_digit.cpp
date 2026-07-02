#include<iostream>
using namespace std;

int main()
{
    int number;
    int sum = 0;

    cout << "Enter a Number: ";
    cin >> number;

    // Sum of digits: Number ke sabhi digits ka addition.

    while (number > 0)
    {
        int lastDigit = number % 10;
        sum = sum + lastDigit;
        number = number / 10;
    }

    cout << "Sum of digits is " << sum;

    return 0;
}