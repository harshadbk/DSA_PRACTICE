#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool calcday(vector<int> &nums, int pack, int days)
{
    int day = 1;
    int sum = 0;

    for (int num : nums)
    {
        sum += num;
        if (sum > pack)
        {
            sum = num;
            day++;
        }
    }

    return day <= days;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int l = -1;
    int r = 0;

    for (int num : nums)
    {
        l = max(l, num);
        r += num;
    }

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (calcday(nums, mid, days))
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