#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int tar = 0;

    int st = 0;
    int ed = nums.size() - 1;

    while (st <= ed)
    {
        int mid = st + (ed - st) / 2;

        if (nums[mid] == tar)
        {
            cout << mid;
            return 0;
        }

        else if (nums[st] <= nums[mid])
        {
            if (tar >= nums[st] && tar <= nums[mid])
            {
                ed = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (tar >= nums[mid] && tar <= nums[ed])
            {
                st = mid + 1;
            }
            else
            {
                ed = mid - 1;
            }
        }
    }

    cout << -1;

    return 0;
}