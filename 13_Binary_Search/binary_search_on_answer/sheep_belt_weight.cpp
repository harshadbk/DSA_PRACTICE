#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isvalidassignment(vector<int> &arr, int m, int size, int maximumweight)
{
    int days = 1;
    int currentweight = 0;

    for (int i :arr)
    {
        if (arr[i] > maximumweight)
        {
            return false;
        }

        if (arr[i] + currentweight <= maximumweight)
        {
            currentweight += arr[i];
        }
        else
        {
            days++;
            currentweight = arr[i];
        }
    }

    return days <= m;
}

int maximum_load(vector<int> &arr, int size, int days)
{
    sort(arr.begin(), arr.end());

    int ed = 0;
    int st = *max_element(arr.begin(), arr.end());
    for (int x : arr)
        ed += x;
    int ans = ed;
    while (st <= ed)
    {
        int mid = st + (ed - st) / 2;
        if (isvalidassignment(arr, days, size, mid))
        {
            ans = mid;
            ed = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int size = arr.size();
    cout << maximum_load(arr, size, days);
    return 0;
}