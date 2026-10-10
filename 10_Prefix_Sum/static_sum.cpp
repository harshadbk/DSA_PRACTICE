#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {2,4,6,8,10};
    int l = 1;
    int r = 1;

    vector<int> psum;
    psum.resize(nums.size()+1,0);

    for(int i=0;i<nums.size();i++){
        psum[i+1] = (psum[i] + nums[i]);
    }

    int sum = psum[r+1] - psum [l];
    cout << sum;

    return 0;
}