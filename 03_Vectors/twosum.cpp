#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<vector>
using namespace std;

vector<int> twosump(vector<int> &arr,int sum){
    unordered_map<int,int> mp;

    for(int i=0;i<arr.size();i++){
        int need = sum - arr[i];
        if(mp.find(need) != mp.end()){
            return {mp[need],i};
        }
        mp[arr[i]] = i;
    }
    return {};
}

int main() {

    vector<int> arr {12,4,5,3,8,17,21};
    int sum = 27;
    
    vector<int> ans = twosump(arr,sum);

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }

    return 0;
}