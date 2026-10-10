#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {4,5,6,7,1,2,3};
    int l = 0;
    int r = nums.size()-1;

    while(l<r){
        int mid = l + (r-l) / 2;
        if(nums[mid] > nums[r]){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << nums[l];
    return 0;
}