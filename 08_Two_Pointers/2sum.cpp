#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {2,7,11,15};
    int tar = 9;
    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        int comp = tar - nums[i];
        if(mp.find(comp) != mp.end()){
            cout << i+1 << " " << mp[comp] << endl;
            return 0;
        }
        mp[nums[i]] = i+1;
    }

    cout << -1;
    return 0;
}