#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> smallestCount (vector<int> &arr,int size){
    vector<int> ans ;
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    vector<int> arr = {5,2,6,1};
    int size = arr.size();
    vector<int> ans = smallestCount(arr,size);
    for(int x:ans){
        cout << x<<endl;
    }
    return 0;
}