#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<string> str {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string,vector<string>> ans;
    vector<vector<string>> grouped;

    for(string st:str){
        string k = st;
        sort(k.begin(),k.end());
        ans[k].push_back(st);
    }

    for(auto& it:ans){
        grouped.push_back(it.second);
    }

    for(int i=0;i<grouped.size();i++){
        for(int j=0;j<grouped[i].size();j++){
            cout << grouped[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}