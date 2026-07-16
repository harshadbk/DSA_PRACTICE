#include <iostream>
#include <string>
#include <vector>
using namespace std;

void strpermu(string &str, int idx)
{
    if (idx==str.size())
    {
        cout << str << endl;
        return;
    }
    for (int i = idx; i < str.size(); i++)
    {
        swap(str[i], str[idx]);
        strpermu(str, idx + 1);
        swap(str[i], str[idx]);
    }
}

int main()
{
    string str = "abc";
    strpermu(str, 0);
    return 0;
}