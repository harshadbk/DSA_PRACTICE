#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> countSmallest(vector<int>&arr,int size){
    vector<int> ans(arr.size());
    vector<int> sorted;
    for(int i=size-1;i>=0;--i){
        int pos = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
        ans[i] = pos;
        sorted.insert(sorted.begin()+pos,arr[i]);
    }

    return ans;
}

int main(){
    vector<int> arr = {5,2,6,1};
    int size = arr.size();
    vector<int> ans = countSmallest(arr,size);
    for(int i=0;i<size;i++){
        cout << ans[i] << endl;
    }
    return 0;
}