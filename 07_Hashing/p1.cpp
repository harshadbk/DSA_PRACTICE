#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {2,9,7,5,11,3,29};
    unordered_map<int,int> mp;
    int tar = 16;

    for(int i=0;i<nums.size();i++){
        int comp = tar - nums[i];

        if(mp.count(comp)){
            cout << i+1 << " " << mp[comp];
            return 0;
        }

        mp[nums[i]] = i+1;
    }

    cout << -1;

    return 0;
}