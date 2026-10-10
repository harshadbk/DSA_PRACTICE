#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "dztz";
    vector<vector<int>> shifts{
        {0, 0, 0},
        {1, 1, 1}};
        
    int n = s.size();

    vector<int> diff (n+1,0);

    for(auto& shift : shifts){
        int st = shift[0];
        int ed = shift[1];

        int val = shift[2]==1 ? 1:-1;

        diff[st] += val;
        diff[ed+1] -= val;
    }

    int currs = 0;

    for(int i=0;i<n;i++){
        currs += diff[i];

        int x = (s[i] - 'a' + currs) % 26;

        if(x<0){
            x+=26;
        }

        s[i] = 'a' + x;
    }

    cout << s;

    return 0;
}