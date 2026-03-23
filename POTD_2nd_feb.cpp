#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void minremove(vector<int> &nums, int k) {
    int n = nums.size();
    if (n <= 1) {
        cout << 0;
        return;
    }

    sort(nums.begin(), nums.end());

    int i = 0;
    int maxl = 0;

    for (int j = 0; j < n; j++) {
        while (nums[i] * k < nums[j]) {
            i++;
        }
        maxl = max(maxl, j - i + 1);
    }

    cout << n - maxl;
}

int main() {
    vector<int> nums{2,1,5};
    int k = 2;
    minremove(nums, k);
    return 0;
}