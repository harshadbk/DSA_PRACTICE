#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {1,2,3,1};
    int k = 3;
    vector<pair<int,int>> mp;

    for(int i=0;i<nums.size();i++){
        mp.push_back({nums[i],i});
    }

    sort(mp.begin(),mp.end());

    for(int i=0;i<nums.size();i++){
        if(mp[i].first==mp[i+1].first){
            if(abs(mp[i].second-mp[i+1].second) <= k){
                cout << "True";
                return 0;
            }
        }
    }

    cout << "False";
    return 0;
}