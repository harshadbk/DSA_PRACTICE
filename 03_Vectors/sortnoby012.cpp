#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {1,1,0,0,2,1,2,0,0,1,2};

    int size = nums.size();

    int l=0;
    int h = size-1;
    int mid = (l+(h-l))/2;

    while(mid<=h){

        if(nums[mid]==0){
            swap(nums[l],nums[mid]);
            l++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[h]);
            h--;
        }
    }

    for(int i=0;i<size;i++){
        cout << nums[i] << endl;
    }
    
    return 0;
}