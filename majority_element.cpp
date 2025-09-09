#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void majority_element(int arr [],int size){
    for(int i=0;i<size;i++){
        int freq = 0;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){    // brute force approach
                freq++;
            }
        }
         if(freq > (size/2)){
            cout << arr[i];
            break;
        }
    }
    
}

void majority_element2(vector<int>& vec){
    int n = vec.size();
    sort(vec.begin(), vec.end());
    int freq = 1;
    int ans = vec[0];
   for(int i=1;i<n;i++){
        if(vec[i]==vec[i-1]){         // more optimize
            freq++;
        }
        else{
            freq = 1;
            ans = vec[i];
        }
        if(freq > n/2){
            cout << ans;
        }
   }
};

void majority_element3(vector<int>& vec){
    int n = vec.size();
    int freq = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
      if(freq == 0){
        ans = vec[i];
      }
      if(ans == vec[i]){
        freq ++;
      }
      else{
        freq--;
      }
    }
    cout << ans;
}

int main(){
    int arr [] ={1,2,3,1,1};
    vector<int> vec= {1,2,3,1,1};

    int size = 5;
    majority_element(arr,size);
    majority_element2(vec);
    majority_element3(vec);
    return 0;
}