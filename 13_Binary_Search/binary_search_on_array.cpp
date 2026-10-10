#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate_time(vector<int> &nums,int mid){
    int ttime = 0;
    for(int num:nums){
        ttime += (num + (mid-1)) / mid;
    }
    return ttime;
}

int main() {
    vector<int> nums {30,11,23,4,20};
    int t = 6;
    int max = *max_element(nums.begin(),nums.end());
    int l = 1;
    int r = max;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l) / 2;
        int ttime = calculate_time(nums,mid);
        if(ttime <= t){
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}