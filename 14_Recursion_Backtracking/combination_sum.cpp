#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<vector<int>> s;

void combine(vector<int> &arr,int idx,vector<int> &combin,vector<vector<int>> &ans,int tar){
    if(idx>=arr.size() || tar<0){
        return;
    }

    if(tar==0){
        if(s.find(combin)==s.end()){
            s.insert(combin);
            ans.push_back(combin);
        }   
    }

    combin.push_back(arr[idx]);
    combine(arr,idx+1,combin,ans,tar-arr[idx]); // single call
    combine(arr,idx,combin,ans,tar-arr[idx]); // multiple single call

    combin.pop_back();
    combine(arr,idx+1,combin,ans,tar); // exclusion call
}

int main(){
    vector<vector<int>> ans;
    vector<int> comb;
    vector<int> arr = {2,3,6,7};
    int tar = 7;
    combine(arr,0,comb,ans,tar);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}