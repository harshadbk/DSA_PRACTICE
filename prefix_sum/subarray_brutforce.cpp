#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {1,2,3,3,5,1,2,4,5,6,7};
    int tar = 3;
    int count = 0;
    
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum==tar){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}