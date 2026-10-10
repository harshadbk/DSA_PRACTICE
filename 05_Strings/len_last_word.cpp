#include <iostream>
using namespace std;

int len_word(string s)
{
    int i = s.length() - 1;
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    int len = 0;
    while (i>=0 && s[i] != ' ')
    {
        i--;
        len++;
    }

    return len;
    
}

int main()
{
    string s = "   fly me   to   the moon  ";
    cout << len_word(s);
    return 0;
}