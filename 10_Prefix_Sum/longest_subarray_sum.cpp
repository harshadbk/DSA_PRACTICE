#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main() {
    vector<int> nums {3,-1,5,-3,3};
    unordered_map<int,int> mp;
    mp[0] = -1;
    int k = 3;
    int sum = 0;
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(mp.count(sum-k)){
            ans = max(ans,i-mp[sum-k]);
        }
        if(!mp.count(sum)){
            mp[sum] = i;
        }
    }
    cout << ans;
    return 0;
}