#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool is_valid_assignment(vector<int> &arr,int size,int c,int allowedDistance){
    int cow = 1;
    int laststallpos = arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]-laststallpos >= allowedDistance){
            cow ++;
            laststallpos = arr[i];
        }
        if(cow==c){
            return true;
        }
    }
    return false;
}

int aggressive_cow(vector<int> &arr,int size,int c){
    sort(arr.begin(),arr.end());
    int st = 1;
    int ed = arr[size-1]-arr[0];
    int ans=-1;
    while (st<=ed)
    {
        int mid = st+(ed-st)/2;
        if(is_valid_assignment(arr,size,c,mid)){
           ans = mid;
           st = mid+1;
        }
        else{
            ed = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={1,2,8,4,9};
    int n = 5;
    int c = 3;
    cout << aggressive_cow(arr,n,c);
    return 0;
}