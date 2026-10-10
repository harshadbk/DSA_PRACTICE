#include <iostream>
#include <vector>
using namespace std;

int minpenalty(string customer)
{
    int totalY = 0;
    for (char ch : customer)
    {
        if (ch == 'Y')
        {
            totalY++;
        }
    }

    int openp = 0;
    int closep = totalY;
    int minp = totalY;
    int ans = 0;

    for (int j = 0; j < customer.size(); j++)
    {
        if (customer[j] == 'Y')
        {
            closep--;
        }
        else
        {
            openp++;
        }

        int currp = closep + openp;
        if (currp < minp)
        {
            minp = currp;
            ans = j + 1;
        }
    }
    return ans;
}

int main()
{
    string cs = "NNNNN";
    cout<<minpenalty(cs);
    return 0;
}