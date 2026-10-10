#include <iostream>
#include <vector>
using namespace std;

void bs(vector<int> &arr , int tar){
    int s = 0;
    int e = arr.size()-1;
    while(s<=e){
        int mid = s+(e-s) / 2;
        if(arr[mid]==tar){
            cout << mid;
            return ;
        }
        else if(arr[mid] > tar){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    cout << -1;
}
int main() {
    vector<int> arr {1,2,3,4,7,8,9,10,12,13};
    int tar = 3;
    bs(arr,tar);   
    return 0;
}