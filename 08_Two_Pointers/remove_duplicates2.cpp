#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {1,2,2,2,3,3,3,4,5,6,6,7};
    int k = 2;

    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        if(mp[nums[i]] < k){
            mp[nums[i]]++;
        }
    }
    int count = 0;
    for(auto &map:mp){
        count += map.second;
    }

    cout << count;
    return 0;
}