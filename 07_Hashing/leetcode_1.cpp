#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int tar = 9;

    unordered_map<int, int> mp;

    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        int comp = tar - nums[i];

        if (mp.count(comp))
        {
            cout << i + 1 << " " << mp[comp];
            break;
        }

        mp[nums[i]] = i + 1;
    }

    cout << -1 << " " << -1;

    return 0;
}