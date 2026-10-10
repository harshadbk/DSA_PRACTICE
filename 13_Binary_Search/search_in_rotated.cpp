#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {4,5,6,7,1,2,3};
    int tar = 2;
    int st = 0;
    int ed = nums.size()-1;

    while(st<ed){
        int mid = st + (ed-st) /2;

        if(nums[mid]==tar){
            cout << mid;
            return 0;
        }
        else if(nums[mid] > nums[st]){
            if(tar >= nums[st] && tar <= nums[mid]){
                ed = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        else {
            if(nums[ed] >= nums[mid]){
                st = mid + 1;
            }
            else {
                ed = mid -1;
            }
        }
    }
    cout << 0;
    return 0;
}