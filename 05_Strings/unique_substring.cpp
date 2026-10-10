#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int atmost(string s, int k)
{
    unordered_map<char, int> mp;

    int left = 0;
    int ans = 0;

    for (int rit = 0; rit < s.size(); rit++)
    {
        mp[s[rit]] ++;
        while(mp.size() > k){
            mp[s[left]]--;
            if(mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            left++;
        }
        ans += (rit-left+1);
    }
    return ans;
}

int main()
{

    string s = "ababd";
    int k = 2;

    cout << atmost(s, k) - atmost(s, k - 1);

    return 0;
}