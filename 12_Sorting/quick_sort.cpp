#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int st, int ed)
{
    int idx = -1;
    int pivot = nums[ed];
    for(int i=0;i<ed;i++){
        if(nums[i]<=pivot){
            idx++;
            swap(nums[i],nums[idx]);
        }
    }
    idx++;
    swap(nums[ed],nums[idx]);
    return idx;
}

void quick_sort(vector<int> &nums, int st, int ed)
{
    if (st < ed)
    {
        int pivot = partition(nums, st, ed);
        quick_sort(nums, st, pivot - 1);
        quick_sort(nums, pivot + 1, ed);
    }
}

int main()
{
    vector<int> nums = {67, 54, 33, 12, 23, 4, 98, 31};
    quick_sort(nums, 0, nums.size() - 1);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}