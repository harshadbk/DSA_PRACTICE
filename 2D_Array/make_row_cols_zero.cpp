#include<iostream>
#include<vector>
using namespace std;

bool make_zeros(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();

    bool firstrowzero = false;
    bool firstcolszero = false;

    // step1 check if 1st row has 0 element
    for(int i=0;i<n;i++){
        if(arr[0][i]==0){
            firstrowzero = true;
        }
    }
    // step2 check if 1st cols has 0 element
    for(int i=0;i<m;i++){
        if(arr[i][0]==0){
            firstcolszero = true;
        }
    }

    // step 3 marks 0 using first row and cols

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]==0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    // step 4 use marks for setting cells to 0

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(arr[0][j]==0 || arr[i][0]==0){
                arr[i][j] = 0;
            }
        }
    }

    // step 5 set 0 into first row and cols if needed
       if(firstrowzero) {
            for(int j = 0; j < n; j++) {
                arr[0][j] = 0;
            }
        }

           if(firstcolszero) {
            for(int j = 0; j < n; j++) {
                arr[j][0] = 0;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << arr[i][j] <<" ";
            }
            cout << endl;
        }
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{0,1,2},{4,5,6}};
    make_zeros(arr);
    return 0;
}