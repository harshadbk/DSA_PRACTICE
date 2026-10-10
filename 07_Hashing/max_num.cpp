#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums {1,2,2,2,1,1,2,2,2,2,1,1,1,1};
    int freq = 0;
    int mnum;

    for(int num:nums){
        if(freq==0){
            mnum = num;
        }
        if(mnum == num){
            freq ++;
        }
        if(mnum != num){
            freq --;
        }
    }
    cout << mnum;
    return 0;
}