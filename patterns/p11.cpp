#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        { // first star
            cout << "*";
        }
        for (int k = 0; k < 2 * (n - i - 1); k++)
        {
            cout << " ";
        }
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n - i; k++)
        {
            cout << "*";
        }
        if (i != 0)
        {
            for (int j = 0; j < 2 * (i); j++)
            {
                cout << " ";
            }
        }
        for (int l = 0; l < n - i; l++)
        {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}