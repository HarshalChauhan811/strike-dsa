#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the Number, You want to calculate factorial: ";
    cin >> num;

    // Factorial: Kisi number se 1 tak ke sabhi positive numbers ka multiplication.

    int fact = 1;

    if (num < 0)
    {
        cout << "Factorial of a negative number is not defined.";
        return 0;
    }

    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }

    cout << "The factorial of " << num << " is " << fact;

    return 0;
}