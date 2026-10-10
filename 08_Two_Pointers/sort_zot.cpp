#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> arr {1,2,0,0,2,1,1,0,0,0,1,2,1,0,0,1};

    int l =0;
    int h = arr.size()-1;
    int m = 0;
    while(m<=h){
        if(arr[m]==0){
            swap(arr[m],arr[l]);
            m++;
            l++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            swap(arr[h],arr[m]);
            h--;
        }
    }

    for(int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
    
    return 0;
}