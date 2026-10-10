#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool isfound(vector<int> &arr,int size,int k){
    unordered_map<int,int>mp;
    mp[0]=-1;

    int prefixsum = 0;

    for(int i=0;i<size;i++){
        prefixsum += arr[i];
        if(k!=0){
            prefixsum = prefixsum % k;
        }
        if(mp.count(prefixsum)){
            if(i-mp[prefixsum]>=2){
                return true;
            }
        }
        else{
                mp[prefixsum] = i;
            }
        
    }
    return false;
}


int main(){
    vector<int> arr = {23,2,4,6,7};
    int size = arr.size();
    int k = 10;
    cout << isfound(arr,size,k);
    return 0;
}