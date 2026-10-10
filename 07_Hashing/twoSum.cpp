#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i+1};
            }
            mp[nums[i]] = i+1;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = s.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: ";
        for(int x : result){
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
