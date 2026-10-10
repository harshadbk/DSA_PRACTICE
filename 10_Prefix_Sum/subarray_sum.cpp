#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums {1,2,3};
    int k = 3;
    unordered_map<int,int> mp;
    mp[0] = 1;
    int prefix = 0;
    int count = 0;
    for(int num:nums){
        prefix += num;
        int need = prefix - k;
        if(mp.count(need)){
            count++;
        }
        mp[prefix]++;
    }
    cout << count << endl;
    return 0;
}