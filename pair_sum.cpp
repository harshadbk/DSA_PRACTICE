#include<iostream>
#include<vector>
using namespace std;

// method 1

// void pair_sum(int arr [],int size,int sum){
//     vector<int> ans;
//     for(int i=0;i<size;i++){
//         for(int j=i+1;j<size;j++){
//             if(arr[i]+arr[j] == sum){
//                 ans.push_back(i);
//                 ans.push_back(j);
//             }
//         }
//     }
//     cout << ans[0] << "  " << ans[1];
// };

// method 2

// void pair_sum(int arr [],int size,int sum){
//     vector<int> ans;
//     int i=0,j=size-1;
//     while(i<j){
//         int pair_sum = arr[i] + arr[j];
//         if(pair_sum > sum){
//             j--;
//         }
//         else if(pair_sum < sum){
//             i++;
//         }
//         else{
//             ans.push_back(i);
//             ans.push_back(j);
//             i++;
//             j--;
//         }
//     }
//     cout << ans[0] << "  " << ans[1];
// };

void pair_sum(int arr[], int size, int sum) {
    vector<pair<int, int>> ans;
    int i = 0, j = size - 1;

    while (i < j) {
        int s = arr[i] + arr[j];
        if (s > sum) {
            j--;
        }
        else if (s < sum) {
            i++;
        }
        else {
            ans.push_back({i, j});
            i++;   
            j--;   
        }
    }

    if (ans.empty()) {
        cout << "No pair found\n";
    } else {
        for (auto &p : ans) {
            cout << "Pair: (" << arr[p.first] << ", " << arr[p.second] 
                 << ") at indices (" << p.first << ", " << p.second << ")\n";
        }
    }
}



int main(){
    int arr [] = {1,2,3,4,5};
    int size = 5;
    int sum = 5;
    pair_sum(arr,size,sum);
    return 0;
}