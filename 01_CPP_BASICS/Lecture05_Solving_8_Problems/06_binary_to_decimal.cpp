#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    int first = 0;
    int second = 1;

    // First two Fibonacci numbers
    cout << first << " " << second << " ";

    // Generate remaining Fibonacci numbers
    for (int i = 3; i <= n; i++)
    {
        int curr = first + second;

        cout << curr << " ";

        first = second;
        second = curr;
    }

    return 0;
}