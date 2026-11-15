#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int len = heights.size();
    int l = 0;
    int r = len - 1;
    int leftmax = heights[0];
    int rightmax = heights[len - 1];
    int maxarea = INT16_MIN;

    while (l < r)
    {
        int len = min(leftmax, rightmax);
        maxarea = max(maxarea, (len * (r - l)));

        if (heights[r] < heights[l])
        {
            r--;
            rightmax = max(rightmax, heights[r]);
        }
        else
        {
            l++;
            leftmax = max(leftmax, heights[l]);
        }
    }

    cout << maxarea;

    return 0;
}