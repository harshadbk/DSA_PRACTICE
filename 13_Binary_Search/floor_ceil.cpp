#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {1,2,3,4,6,7,8,9};
    int num = 5;
    int l = 0;
    int r = nums.size()-1;
    int ans = -1;

    while(l<=r){
        int mid = l + (r-l) / 2;

        if(nums[mid]==num){
            ans = mid;
            break;
        }

        else if(nums[mid] > num){
            r = mid - 1;
            ans = r;
        }
        else {
            l = mid+1;
            // ans = l;
        }

    }
    cout << ans;
    return 0;
}