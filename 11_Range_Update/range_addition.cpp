#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int len = 5;
    vector<vector<int>> updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}};

    vector<int> diff(len+1,0);
    vector<int> ans (len,0);

    for(int i=0;i<updates.size();i++){
       int st = updates[i][0];
       int ed = updates[i][1];
       int val = updates[i][2];
       diff[st] += val;
       diff[ed+1] -= val;
    }

    ans[0] = diff[0];

    for(int i=1;i<ans.size();i++){
        ans[i] += ans[i-1] + diff[i]; 
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}