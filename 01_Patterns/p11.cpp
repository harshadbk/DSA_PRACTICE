#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    // Upper half
    for (int i = 0; i < n; i++)
    {
        // left stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        // middle spaces
        for (int k = 0; k < 2 * (n - i - 1); k++)
        {
            cout << " ";
        }

        // right stars
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 1; i < n; i++)
    {
        // left stars
        for (int k = 0; k < n - i; k++)
        {
            cout << "*";
        }

        // middle spaces
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // right stars
        for (int l = 0; l < n - i; l++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}