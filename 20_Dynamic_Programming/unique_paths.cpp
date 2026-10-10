#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

int dp[101][101];

int helper(vector<vector<int>>& grid,int i,int j){
    int m = grid.size();
    int n = grid[0].size();

    if(i>=m || j>=n || grid[i][j]==1){
        return 0;
    }

    if(i==m-1 && j==n-1){
        return 1;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    return dp[i][j] = helper(grid,i+1,j) + helper(grid,i,j+1);
}

int totalcount(vector<vector<int>>& grid){
    memset(dp,-1,sizeof(dp));
    if(grid[0][0]==1){
        return 0;
    }
    return helper(grid,0,0);
}

int main(){
    vector<vector<int>> grid = {{0,0,0},{0,0,0},{0,0,0}};
    cout << totalcount(grid);
    return 0;
}