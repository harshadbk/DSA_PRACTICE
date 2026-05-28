#include <iostream>
#include <vector>
using namespace std;

void maxsubarray(vector<int> &nums){
    int maxsum = INT16_MIN;

    for(int i=0;i<nums.size();i++){
        int currsum = 0;
        for(int j=i;j<nums.size();j++){
            currsum += nums[j];
            maxsum = max(maxsum,currsum);
        }
    }

    cout << maxsum;
}

int main() {

    vector<int> nums {-2, -3, -7, -2, -10, -4};
    maxsubarray(nums);
    return 0;
}