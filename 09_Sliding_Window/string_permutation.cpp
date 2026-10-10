#include <iostream>
#include <vector>
using namespace std;

bool checkpermute(vector<int> &sbct,vector<int> &strct){
    for(int i=0;i<26;i++){
        if(sbct[i] != strct[i]){
            return false;
        }
    }
    return true;
}

int main() {
    string str = "eidbaooo";
    string sb = "ab";

    vector<int> sbct (26,0);

    for(int i=0;i<sb.size();i++){
        sbct[sb[i]-'a']++;
    }

    for(int i=0;i<=str.size()-sb.size();i++){
        vector<int> strct (26,0);
        for(int j=i;j<i+sb.size();j++){
            strct[str[j]-'a']++;
        }
        if(checkpermute(sbct,strct)){
            cout << true;
            return 0;
        }
    }

    cout << false;

    return 0;
}