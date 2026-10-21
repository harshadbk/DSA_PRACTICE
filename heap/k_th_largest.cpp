#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = 3;
    vector<int> nums{12, 45, 32, 11, 19, 23, 33, 18, 4, 41}; // min heap

    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    cout << pq.top();
    return 0;
}