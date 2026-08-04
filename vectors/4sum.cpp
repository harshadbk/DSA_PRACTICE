#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums{2,2,2,2};
    int tar = 8;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int rit = nums.size() - 1;

            while (left < rit)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[rit];

                if (sum == tar)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[rit]});
                    rit--;
                    left++;
                    while (left < rit && nums[left] == nums[left - 1])
                        left++;
                    while (left < rit && nums[rit] == nums[rit + 1])
                        rit--;
                }
                else if (sum > tar)
                {
                    rit--;
                }
                else
                {
                    left++;
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}