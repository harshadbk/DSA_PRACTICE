#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    string s = "abcde";
    string d = "cdeab";

    if(s.size() != d.size()) {cout << false;
    return 0;
    }

    unordered_map<char,int> mp;

    for(char ch:s){
        mp[ch] ++;
    }

    for(char c:d){
        mp[c]--;
        if(mp[c] < 0){
            cout << false;
            return 0;
        }
    }

    cout << true;

    return 0;
}