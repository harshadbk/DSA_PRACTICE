#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string longsub = "abcabcbb";
    vector<int> last(256, 0);
    int left = 0;
    int maxlen = 0;

    for (int i = 0; i < longsub.size(); i++)
    {
        last[longsub[i]]++;

        while (last[longsub[i]] > 1)
        {
            left++;
            last[longsub[i]]--;
        }

        maxlen = max(maxlen, i - left + 1);
    }

    cout << maxlen;

    return 0;
}