#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Fsum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < size; j++)
        {
            if (j > i+1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            int p = j+1;
            int q = size-1;
            while (p < q)
            {
                long long sum = (long long)arr[i] + arr[j] + arr[p] + arr[q];
               
                if (sum < target)
                {
                    p++;
                }
                else if (sum > target)
                {
                    q--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[p], arr[q]});
                    p++;
                    q--;
                    while (p < q && arr[p] == arr[p - 1])
                    {
                        p++;
                    }

                    while (p < q && arr[q] == arr[q - 1])
                    {
                        q--;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};

    vector<vector<int>> result = Fsum(nums, 0);

    cout << "Triplets are:\n";
    for (auto &triplet : result)
    {
        cout << "[ ";
        for (int x : triplet)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}