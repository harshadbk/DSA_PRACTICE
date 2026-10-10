#include <iostream>
using namespace std;

void add(int num, int sum)
{
    if (num == 0)
    {
        cout << sum;
        return;
    }
    sum += num;
    add(num - 1, sum);
}

int main()
{
    int sum = 0;
    add(6, sum);
    return 0;
}