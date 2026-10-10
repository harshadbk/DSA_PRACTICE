#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralborder(vector<vector<int>> &mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    int strow = 0;
    int stcol = 0;
    int edrow = m-1;
    int edcol = n-1;

    while(strow<=edrow && stcol <= edrow){
        // top
        for(int j = stcol;j<=edcol;j++){
            ans.push_back(mat[strow][j]);
        }
        // right
        for(int j=strow+1;j<=edrow;j++){
            ans.push_back(mat[j][edcol]);
        }
        // bottom
        for(int j=edcol-1;j>=stcol;j--){
            if(strow == edrow){
                break;
            }
            ans.push_back(mat[edrow][j]);
        }
        // left
        for(int j=edrow-1;j>=strow+1;j--){
            ans.push_back(mat[j][stcol]);
        }

        strow++;
        edrow--;
        stcol++;
        edcol--;
    }
    return ans;
}

int main(){
        vector<vector<int>> arr {
        {2,5,7,9},
        {10,12,16,20},
        {30,33,34,38}};

    vector<int> ans = spiralborder(arr);
    for(int n:ans){
        cout << n << " ";
    }
    return 0;
}