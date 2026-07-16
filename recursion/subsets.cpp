#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> ans;

void printsubset(vector<int> &vec,vector<int>&subset,int i){
    if(i==vec.size()){
        ans.push_back(subset);
        return;
    }
    subset.push_back(vec[i]);
    printsubset(vec,subset,i+1);
    subset.pop_back();
    printsubset(vec,subset,i+1);
}

int main() {
    vector<int> arr {1,2,3};
    vector<int> subset;
    printsubset(arr,subset,0);

    for(auto &it:ans){
        for(auto &ele:it){
            cout << ele;
        }
        cout << endl;
    }
    return 0;
}