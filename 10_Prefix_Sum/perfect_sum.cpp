#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {23,2,6,4,7};
    int k = 6;
    unordered_map<int,int> mp;
    mp[0]=-1;
    int prefixsum = 0;

    for(int i=0;i<nums.size();i++){
        prefixsum += nums[i];
        int rem = prefixsum % k;
        if(rem < 0){
            rem += k;
        }
        if(mp.count(rem)){
            if(i-mp[rem] >= 2){
                cout << true;
                return 0;
            }
        }
        else{
            mp[rem] = i;
        }
    }

    cout << false;

    return 0;
}