#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

 unordered_map<string, vector<char>> mp;

     void buildNext(string &bottom, int idx, string curr,
                   vector<string> &nextLevels) {

        if (idx == bottom.size() - 1) {
            nextLevels.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);

        if (mp.find(key) == mp.end())
            return;

        for (char ch : mp[key]) {

            buildNext(bottom, idx + 1, curr + ch, nextLevels);
        }
    }

    bool dfs(string bottom) {

        if (bottom.size() == 1)
            return true;

        vector<string> nextLevels;

        buildNext(bottom, 0, "", nextLevels);

        for (string &next : nextLevels) {
            if (dfs(next)) 
                return true;
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        
        return dfs(bottom);
    }

int main()
{
    string bottom = "BCD";
    vector<string> str = {"BCC", "CDE", "CEA", "FFF"};
    cout << pyramidTransition(bottom, str);
    return 0;
}