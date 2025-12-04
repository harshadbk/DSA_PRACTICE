#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reversepair(vector<int> &arr, int size)
{
    vector<long long> reverse;
    int count = 0;

    for (int i = size - 1; i >= 0; --i)
    {
        long long halfval = (arr[i] - 1LL) / 2;
        int pos = upper_bound(reverse.begin(), reverse.end(), halfval) - reverse.begin();
        count += pos;

        long long val = arr[i];
        int insertpos = lower_bound(reverse.begin(), reverse.end(), val) - reverse.begin();
        reverse.insert(reverse.begin() + insertpos, val);
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 1};
    int size = arr.size();
    cout << reversepair(arr, size);
    return 0;
}