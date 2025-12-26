#include<iostream>
#include<vector>
using namespace std;

int paths = 0;
int m;
int n;

void dfs(vector<vector<int>> &grid,int i,int j,int remain){
    // invalid case
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1){
        return;
    }

    // base case

    if(grid[i][j]==2){
        if(remain==0){
            paths++;
        }
        return;
    }
    grid[i][j] = -1;

    // recursive calls

    dfs(grid,i+1,j,remain-1);
    dfs(grid,i-1,j,remain-1);
    dfs(grid,i,j+1,remain-1);
    dfs(grid,i,j-1,remain-1);

    // backtrack

    grid[i][j] = 0;
}

int maxpaths(vector<vector<int>> &grid){
    m = grid.size();
    n = grid[0].size();

    int stx , sty;
    int remain = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=-1){
                remain++;
            }
            if(grid[i][j]==1){
                stx = i;
                sty = j;
            }
        }
    }

    dfs(grid,stx,sty,remain-1);
    return paths;
}

int main() {

    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    cout << maxpaths(grid) << endl;

    return 0;
}