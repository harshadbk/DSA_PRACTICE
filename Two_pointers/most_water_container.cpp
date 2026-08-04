#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {1,1};
    int maxwater = 0;
    int l = 0;
    int r = nums.size()-1;

    while(l<r){
        int h = r-l;
        int width = min(nums[r],nums[l]);
        maxwater = max(maxwater,(h*width));
        if(nums[r] > nums[l]){
            l++;
        }
        else {
            r--;
        }
    }
    
    cout << maxwater << endl;

    return 0;
}