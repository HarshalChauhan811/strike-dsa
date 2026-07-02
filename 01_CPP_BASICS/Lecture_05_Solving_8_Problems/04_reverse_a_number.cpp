#include<iostream>
using namespace std;

int main()
{
    int number;
    int ans = 0;

    cout << "Enter a Number: ";
    cin >> number;

    // Reverse a number using modulo (%) and division (/).

    while (number > 0)
    {
        int lastDigit = number % 10;
        number = number / 10;
        ans = ans * 10 + lastDigit;
    }

    cout << "Reverse of the number is " << ans;

    return 0;
}