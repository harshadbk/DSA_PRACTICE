#include <iostream>
#include <vector>
using namespace std;

void maxsubarraysum(vector<int> &arr){
    int maxsum = INT16_MIN;
    int sum = INT16_MIN;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(sum > maxsum){
            maxsum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    cout << maxsum;
}

int main() {

    vector<int> arr {-1,2,3,4,5,-2,-3,-9,11,21};

    maxsubarraysum(arr);
    
    return 0;
}