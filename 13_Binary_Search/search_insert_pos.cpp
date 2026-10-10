#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {2,3,4,5,6,7,9,11,15};
    int tar = 10;
    int l = 0;
    int r = nums.size()-1;

    while(l<=r){
        int mid = l + (r-l) / 2;
        if(nums[mid]==4){
            cout << mid;
            return 0;
        }
        else if(tar > nums[mid]){
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}