#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {1,2,3,4,5,1,2};

    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }

    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size();i++){
        if(mp[nums[i]] == 1){
            cout << nums[i];
            break;
        }
    }

    return 0;
}