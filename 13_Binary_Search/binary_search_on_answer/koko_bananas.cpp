#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calchours(vector<int> &nums, int piles, int h)
{
    int totalhours = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        totalhours += ((nums[i] + piles - 1) / piles);
    }
    return totalhours;
}

int main()
{
    vector<int> nums{3, 6, 7, 11};
    int h = 8;

    int l = 1;
    int r = *max_element(nums.begin(), nums.end());

    int ans = INT16_MAX;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (calchours(nums, mid, h) <= h)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}