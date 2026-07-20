#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {4,5,6,1,2,3};
    int tr = 2;

    int st = 0;
    int ed = nums.size()-1;

    while(st <= ed){
        int mid = st + (ed-st) / 2;
        if(nums[mid]==tr){
            cout << "Found";
            return 0;
        }
        else if(nums[mid] >= nums[st]){
            if(tr >= nums[st] && tr < nums[mid]){
                ed = mid -1;
            }
            else {
                st = mid + 1;
            }
        }
        else {
            if(tr > nums[mid] && tr <= nums[ed]){
                st = mid + 1;
            }
            else {
                ed = mid - 1;
            }
        }
    }
    cout << "Not Found";
    return 0;
}