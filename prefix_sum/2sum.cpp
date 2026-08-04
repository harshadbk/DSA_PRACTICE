#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {1,3,4,7,6,2,2,9,8,12,3};
    int k = 4;

    unordered_map<int,int> mp;
    int count = 0;
    mp[0] = 1;
    int totalsum = 0;

    for(int num:nums){
        totalsum += num;
        int rem = totalsum - k;

        if(mp.find(rem) != mp.end()){
            count += mp[rem];
        }
        mp[totalsum]++;
    }
    cout << count;
    return 0;
}