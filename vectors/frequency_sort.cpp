#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {2,3,4,5,1,2,3,4,6,7,8,6,5,4,3,2,1,2,3,3,3,3,1,1,6,7,8,9};
    unordered_map<int,int> mp;
    for(int num:nums){
        mp[num]++;
    }
    vector<pair<int,int>> pr (mp.begin(),mp.end());

    sort(pr.begin(),pr.end(),[](auto &a,auto &b){
        if(a.second == b.second) {
         return a.first < b.first;
        }
        return a.second > b.second;
    });
   int st = 0;
   for(auto &a:pr){
    int val = a.first;
    int freq = a.second;
    for(int i=st;i<st+freq;i++){
        nums[i] = val;
    }
    st+=freq;
   }

   for(int i=0;i<nums.size();i++){
    cout << nums[i] << " ";
   }
    return 0;
}