#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {-1,2,9};
    unordered_map <int,int> mp;
    int k = 2;

    mp[0] = 1;
    int count = 0;
    int prefixsum = 0;

    for(int num:nums){
        prefixsum += num;
        int rem = prefixsum % k;
        if(rem < 0){
            rem += k;
        }
        if(mp.count(rem)){
            count += mp[rem];
        }

        mp[rem] ++;
    }
    
    cout << count << endl;
    return 0;
}