#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a Number: ";
    cin >> num;

    int ans = 0;

    // Negative number ka square root real number me nahi hota
    if (num < 0)
    {
        cout << "Square root is not defined.";
        return 0;
    }

    // Find the integer square root
    for (int i = 1; i * i <= num; i++)
    {
        ans = i;
    }

    cout << "Square Root = " << ans;

    return 0;
}