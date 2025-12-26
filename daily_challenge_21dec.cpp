#include<iostream>
#include<vector>
using namespace std;

int deletecount(vector<string> &strs){
    int m = strs.size();
    int n = strs[0].size();
    vector<bool> sorted(m-1,false);
    int deletion = 0;
    for(int col=0;col<n;col++){
        bool needelete = false;
        for(int row=0;row<m-1;row++){
            if(!sorted[row] && strs[row][col] > strs[row+1][col]){
                needelete = true;
                break;
            }
        }
        if(needelete){
            deletion++;
        }
        else{
            for(int row=0;row<m-1;row++){
                if(!sorted[row] && strs[row][col] < strs[row+1][col]){
                    sorted[row] = true;
                }
            }
        }
    }
    return deletion;
}

int main(){
    vector<string> strs = {"ca", "bb", "ac"};
    cout << deletecount(strs);
    return 0;
}