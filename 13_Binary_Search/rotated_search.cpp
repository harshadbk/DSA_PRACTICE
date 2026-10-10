#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {3,4,5,6,7,8,9,1,2};
    int tar = 8;
    int l = 0;
    int r = nums.size()-1;

    while(l<=r){
        int mid = l + (r-l) / 2;
        if(nums[mid]==tar){
            cout << mid;
            return 0;
        }
        else if(nums[mid] >= nums[l]){
            if(nums[l] <= tar && nums[mid]> tar){
                r = mid -1;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if(nums[r] >= tar && nums[mid] < tar){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    cout << -1;
    return 0;
}