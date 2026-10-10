#include<iostream>
#include<vector>
using namespace std;

void deadplay(vector<vector<int>> &mat){
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> dir = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,1},
        {1,-1},{1,0},{1,1}
    };

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int live = 0;
            for(auto &d:dir){
                int x = i+d[0];
                int y = j+d[1];
                if(x>=0 && x<m && y>=0 && y<n && (mat[x][y]==1||mat[x][y]==-1)){
                    live++;
                }
            }
            // live -> dead

            if(mat[i][j]==1 &&(live<2||live>3)){
                mat[i][j]=-1;
            }

            // dead -> live

            if(mat[i][j]==0 && live==3){
                mat[i][j] =2;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]>0){
                mat[i][j] = 1;
            }
            else{
                mat[i][j] = 0;
            }
            
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Initial Board:\n";
    for (auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    deadplay(mat); 

    cout << "\nNext Generation:\n";
    for (auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
