#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> partitioning(vector<int> &arr,int pivot,int size){
    vector<int> low , equal , high;

    for(int x:arr){
        if(x>pivot){
            high.push_back(x);
        }
        else if(x<pivot){
            low.push_back(x);
        }
        else{
            equal.push_back(x);
        }
    }
    vector<int> ans;
    ans.reserve(arr.size());
    ans.insert(ans.end(),low.begin(),low.end());
    ans.insert(ans.end(),equal.begin(),equal.end());
    ans.insert(ans.end(),high.begin(),high.end());

    return ans;
}

int main(){
    vector<int> arr = {9, 7, 11, 23, 20, 10, 4, 7, 8, 11};
    int pivot = 11;
    int size = arr.size();
    vector<int> ans = partitioning(arr,pivot,size);

    for(int i=0;i<size;i++){
        cout << ans[i] << " ";
    }
    return 0;
}