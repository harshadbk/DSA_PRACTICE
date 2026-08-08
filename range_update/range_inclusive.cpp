#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> ranges = {{1, 2},
                                  {3, 4},
                                  {5, 6}};

    int l = 2;
    int r = 5;

    vector<int> diff(52,0);

    for(auto &range:ranges){
        int st = range[0];
        int ed = range[1];

        diff[st]++;
        diff[ed+1]--;
    }

    int count = 0;

    for(int i=1;i<=50;i++){
        count += diff[i];
        if(i>=l && i<= r && count == 0){
            cout << "False";
            return 0;
        }
    }

    cout << "True";

    return 0;
}