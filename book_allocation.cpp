#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int> &arr,int n , int m,int maximumallowedpages){
    int std = 1;
    int pages = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>maximumallowedpages){
            return -1;
        }
        if(pages + arr[i] <= maximumallowedpages){
            pages += arr[i];
        }
        else{
            std ++;
            pages = arr[i];
        }
    }
    return std > m ? false : true;
}

int allocatebook(vector<int> &arr,int n , int m){
    if(m>n){
        return -1;
    }

    int sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int ans = -1;
    int st = 0;
    int end = sum;
    while (st<=end)
    {
        int mid = st+(end-st)/2;
        if(isvalid(arr,n,m,mid)){
           ans = mid;
           end = mid - 1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {2,2,3,4};
    int n=4;
    int m = 2;
    cout << allocatebook(arr,n,m);

    return 0;
}

// done