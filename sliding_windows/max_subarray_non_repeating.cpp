#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string str = "bbbbb";
    unordered_map<char,int> mp;
    int maxcount = INT16_MIN;
    int left = 0;

    for(int i=0;i<str.size();i++){
        mp[str[i]] ++;
        while(mp[str[i]] > 1){
            mp[str[left]]--;
            left++;
        }
        maxcount = max(maxcount,i-left+1);
    }

    cout << maxcount;

    return 0;
}