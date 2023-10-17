#include <bits/stdc++.h>

using namespace std;

int fib_rec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}

int fib(int n)
{
    int n1 = 0;
    int n2 = 1;
    int n3 = 1;
    if (n == 1)
        return n1;
    else if (n == 2)
        return n2;
    for (int i = 0; i < n; i++)
    {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    cout << "\nUsing recurssion: " << fib_rec(n - 1) << endl;
    cout << "\nUsing iteration: " << fib_rec(n - 1) << endl;
    return 0;
}