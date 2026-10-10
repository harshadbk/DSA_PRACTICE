#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    // vector<int> mp {1,1,2,2,3,4,4,5,1,1,2,3,4,5,6};
    vector<int> arr {1,2,3,2,2};
    unordered_map<int,int> mp;
    int left = 0;
    int maxlen = 0;

    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        if(mp.size()>2){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        if(mp.size()<=2){
            maxlen = max(maxlen,i-left+1);
        }
    }

    cout << maxlen;

    return 0;
}