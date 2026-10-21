#include <iostream>
#include <queue>
using namespace std;

int main()
{
    vector<int> nums{12, 45, 32, 11, 19, 23, 33, 18, 4, 41};
    priority_queue<int> pq; // max heap
    int k = 3;

    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        int t = pq.top();

        if (nums[i] < t)
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    cout << pq.top();
    return 0;
}