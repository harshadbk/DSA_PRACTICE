#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spiral(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int strow = 0, stcol = 0;
    int edrow = n - 1, edcol = n - 1;
    int val = 1;

    while (strow <= edrow && stcol <= edcol)
    {
        // top
        for (int j = stcol; j <= edcol; j++)
        {
            ans[strow][j] = val++;
        }
        // left
        for (int j = strow + 1; j <= edrow; j++)
        {
            ans[j][edcol] = val++;
        }
        // bottom
        if (strow < edrow)
        {
            for (int j = edcol - 1; j >= stcol; j--)
            {
                ans[edrow][j] = val++;
            }
        }

        // right
        if (stcol < edcol)
        {
            for (int j = edrow - 1; j >= strow + 1; j--)
            {
                ans[j][stcol] = val++;
            }
        }
        strow++;
        edrow--;
        stcol++;
        edcol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> ans = spiral(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}