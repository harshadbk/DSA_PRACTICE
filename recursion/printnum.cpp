#include <iostream>
using namespace std;

void printnum(int n)
{
    if (n == 0)
    {
        return;
    }
    printnum(n - 1);
    cout << n << " ";
}

int main()
{
    printnum(7);
    return 0;
}