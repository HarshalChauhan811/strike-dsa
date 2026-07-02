#include<iostream>
using namespace std;

int main()
{
    int num;

    cout << "Enter Number:";
    cin >> num;

    // 2 se small value kabhi prime nahi hoti hai 
    if (num < 2)
    {
        cout << num << " is not a Prime Number";
        return 0;
    }
    
    // 2 se num-1 tak divide krke check krna 
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << " is not a Prime Number";
            return 0;
        }
    }
   cout << num << " is a Prime Number";
}

