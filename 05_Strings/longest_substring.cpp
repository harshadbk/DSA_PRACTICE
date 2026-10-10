#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int longest(string s,int size){
    vector<int> last(256,-1);
    int maxlen = 0;
    int left = 0;
    for(int i=0;i<size;i++){
        if(last[s[i]]!=-1){
            left = max(left,last[s[i]]+1);
        }

        last[s[i]] = i;

        maxlen = max(maxlen,i-left+1);
    }
    return maxlen;
}

int main(){
    string s = {"abcdabcab"};
    int size = s.length();
    cout << longest(s,size);
    return 0;
}