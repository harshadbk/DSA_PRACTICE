#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> nums {1,2,3,3,2,3};
    int freq = 0;
    int num;

    for(int i=0;i<nums.size();i++){
        if(freq == 0){
           num = nums[i] ;
        }

        if(nums[i]==num){
            freq++;
        }
        else{
            freq--;
        }
    }

    cout << num;
    
    return 0;
}