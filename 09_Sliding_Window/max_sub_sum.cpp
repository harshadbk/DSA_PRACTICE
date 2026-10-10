#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {2,3,1,2,4,3};
    int tar = 7;
    int sum = 0;
    int left = 0;
    int min_size = INT16_MAX;

    for(int i=0;i<nums.size();i++){
        sum += nums[i];

        while(sum >= tar){
            min_size = min(min_size,i-left+1);
            sum -= nums[left];
            left++;
        }
    }
   cout << min_size;
    return 0;
}