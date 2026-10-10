#include <iostream>
#include <vector>
using namespace std;

int bsearch(vector<int> &arr, int key, int st, int ed)
{

    while (st < ed)
    {
        int mid = st + (ed - st) / 2;
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] > key)
        {
            return bsearch(arr, key, st, mid - 1);
        }
        else
        {
            return bsearch(arr, key, mid + 1, ed);
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 45, 78, 91};
    int tar = 78;
    int st = 0;
    int ed = arr.size() - 1;
    cout << bsearch(arr, tar, st, ed);
    return 0;
}