#include <iostream>
using namespace std;

int main()
{
    // =====================================================
    // Binary Triangle Pattern
    // =====================================================

    for (int i = 1; i <= 5; i++)
    {
        bool num = i % 2; // Starting value decide karega (Odd Row -> 1, Even Row -> 0)

        for (int j = 1; j <= i; j++)
        {
            cout << num;
            num = !num; // 1 -> 0 aur 0 -> 1
        }

        cout << endl;
    }

    /*
        Output

        1
        01
        101
        0101
        10101
    */

    // =====================================================
    // Alphabet Triangle
    // =====================================================

    // Har row me A se current character tak print hoga.

    for (char i = 'A'; i <= 'E'; i++)
    {
        for (char j = 'A'; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    /*
        Output

        A
        AB
        ABC
        ABCD
        ABCDE
    */

    // =====================================================
    // Alphabet Triangle (Repeated Character)
    // =====================================================

    // Har row me same alphabet repeat hoga.

    for (char i = 'A'; i <= 'E'; i++)
    {
        for (char j = 'A'; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }

    /*
        Output

        A
        BB
        CCC
        DDDD
        EEEEE
    */

    // =====================================================
    // Palindrome Number Triangle
    // =====================================================

    for (int i = 4; i >= 0; i--)
    {
        // Left Side Spaces

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // Increasing Numbers

        for (int j = 1; j <= 5 - i; j++)
        {
            cout << j;
        }

        // Decreasing Numbers

        for (int j = 5 - i - 1; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }

    /*
            1
           121
          12321
         1234321
        123454321
    */

    // =====================================================
    // Problem Solving
    // =====================================================

    // -----------------------------------------------------
    // Prime Number Check
    // -----------------------------------------------------

    int num;

    cout << "Enter the Number: ";
    cin >> num;

    // 2 se chhoti value kabhi bhi prime nahi hoti.

    if (num < 2)
    {
        cout << num << " is Not a Prime Number";
        return 0;
    }

    // 2 se num-1 tak divide karke check karo.

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << " is Not a Prime Number";
            return 0;
        }
    }

    cout << num << " is a Prime Number" << endl;

    // -----------------------------------------------------
    // Sum of Digits
    // -----------------------------------------------------

    int number = 12345;
    int sum = 0;

    while (number > 0)
    {
        int lastDigit = number % 10; // Last digit nikalo

        sum = sum + lastDigit; // Sum me add karo

        number = number / 10; // Last digit remove karo
    }

    cout << "Sum of Digits: " << sum << endl;

    return 0;
}