#include <iostream>
#include <vector>
using namespace std;

void movezeros(vector<int> &nums)
{
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums{9, 3, 0, 1, 4, 0, 8, 4, 0, 0};

    movezeros(nums);

    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }

    return 0;
}