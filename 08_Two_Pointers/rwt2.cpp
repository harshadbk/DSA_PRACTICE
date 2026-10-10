#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {4,2,0,3,2,5};
    int n =  nums.size();
    vector<int> prefix(nums.size(),0);
    vector<int> suffix(nums.size(),0);

    prefix[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        prefix[i] = max(prefix[i-1],nums[i]);
    }

    suffix[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i] = max(suffix[n-1],nums[i]);
    }

    int water = 0;

    for(int i=0;i<nums.size();i++){
        water += min(prefix[i],suffix[i]) - nums[i];
    }

    cout << water ;

    return 0;
}