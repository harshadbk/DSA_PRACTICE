#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    string str = "AAAAAB";
    int k  = 1;
    vector<int> mp (26,0);
    int ans = 0;
    int left = 0;
    int maxfreq = 0;

    for(int i=0;i<str.size();i++){
       mp[str[i] - 'A'] ++;
       maxfreq = max(maxfreq,mp[str[i]-'A']);
       while((i-left+1) - maxfreq > k){
        mp[str[left]]--;
        left++;
       }
       ans = max(ans,i-left+1);
    }
    cout << ans;
    return 0;
}