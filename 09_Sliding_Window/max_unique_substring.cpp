#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string str = "abcaadaabcbc";
    unordered_map<char, int> mp;

    int l = 0;

    string maxstr = "";

    for (int i = 0; i < str.size(); i++)
    {
        while(mp[str[i]]){
            mp[str[l]]--;
            l++;
        }

        mp[str[i]]++;

        if(maxstr.size() < (i-l+1)){
            maxstr = str.substr(l,i-l+1);
        }
    }

    cout << maxstr;

    return 0;
}