#include <iostream>
#include<vector>
using namespace std;

void maxlen(vector<int> &arr,int n,int k){
    int i=0;
    int j=0;
    int sum = arr[0];
    int maxlen = 0;

    while(j<n){
        while(i<=j && sum > k){
            sum -= arr[i];
            i++;
        }

        if(sum==k){
            maxlen = max(maxlen,j-i+1);
        }

        j++;
        if(j<n){
            sum += arr[j];
        }

    }
    cout << maxlen;
}

int main() {

    vector<int> arr {10,5,3,7,19};

    int n = arr.size();

    int k = 15;

    maxlen(arr,n,k);
    
    return 0;
}