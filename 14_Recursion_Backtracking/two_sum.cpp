#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> find2sum(vector<int> arr, int tar)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        int compliment = tar - arr[i];
        if (mp.find(compliment) != mp.end())
        {
            return {mp[compliment], i};
        }
        mp[arr[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 7, 9, 12};

    int tar = 16;

    vector<int> ans = find2sum(arr, tar);

    if (ans.size() == 0)
    {
        cout << "No pair found";
    }
    else
    {
        cout << ans[0] << " " << ans[1];
    }

    return 0;
}