#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {2,4,6,8,9,12,14,15,17,19};
    int tar = 13;
    int i=0;
    int j=nums.size()-1;

    while(i<=j){
        int mid = i + (j-i) / 2;
        if(nums[mid] == 13){
            cout <<  mid;
            return 0;
        }
        else if(nums[mid] < tar){
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }
    cout << i;
    return 0;
}