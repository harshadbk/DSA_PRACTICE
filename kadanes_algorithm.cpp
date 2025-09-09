#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;

// void max_subarray(int arr [] ,int size){
//      for(int i=0;i<size;i++){
//         for(int j=i;j<size;j++){
//             for(int k=i;k<=j;k++){ // it will print all subarray in array
//               cout << arr[k];
//             }
//             cout << " ";
//         }
//         cout << endl;
//      }
// };

// void max_subarray(int arr[],int size){
//     int max_sum = INT_MIN;
//    for(int i=0;i<size;i++){
//      int csum = 0;
//      for(int j=i;j<size;j++){
//         csum += arr[j];
//         max_sum = max(csum,max_sum);  // it uses O(n^2) kadanes will use O(n)
//      }
//    }
//    cout << max_sum;
// };

void max_subarray(int arr [],int size){
    int csum = 0;int max_sum = INT_MIN;
    for(int i=0;i<size;i++){
        csum += arr[i];
        max_sum = max(csum,max_sum);
        if(csum < 0){
            csum = 0;
        }
    }

    cout << max_sum;
}

int main(){

    int arr [] ={1,2,3,4,5};
    int size = 5;

    max_subarray(arr,size);

    return 0;
}