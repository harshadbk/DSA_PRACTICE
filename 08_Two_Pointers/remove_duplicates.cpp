#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {0,0,1,1,1,2,2,3,3,4,6,7,8,8,8,8,10,11,12};
    unordered_set<int> st {nums.begin(),nums.end()};

    cout << st.size() << endl;

    int num = nums[0];
    int k = 1;

    for(int i=1;i<nums.size();i++){
        if(nums[i] != num){
            num = nums[i];
            k++;
        }
    }
    cout << k;

    return 0;
}