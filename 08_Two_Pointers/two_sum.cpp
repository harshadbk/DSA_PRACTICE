#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {2,3,4,6,7,8,12};
    int target = 11;
    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        int compliment = target - nums[i];
        if(mp.find(compliment) != mp.end()){
            cout << mp[compliment] << " " << i+1 << endl;
            return 0;
        }
        mp[nums[i]] = i+1;
    }
    cout << "Not Found";
    return 0;
}