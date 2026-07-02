#include<iostream>
using namespace std;

int main()
{
    int num = 13;
    int ans = 0;
    int mul = 1;    // Place value (1, 10, 100, 1000...)

    while (num != 0)
    {
        int rem = num % 2;    // Last binary digit
        num = num / 2;        // Reduce the number

        ans = ans + rem * mul;    // Add digit at its correct place
        mul = mul * 10;           // Move to the next place value
    }

    cout << "Binary = " << ans;

    return 0;
}