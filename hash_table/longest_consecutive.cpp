#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> nums{100,4,200,1,3,2};

    unordered_set<int> st (nums.begin(),nums.end());
    int longest = 0;
    for(int num:nums){
        if(st.find(num-1) == st.end()){
            int count = 1;
            int curr = num;

            while(st.find(curr+1)!=st.end()){
                count++;
                curr++;
            }

            longest = max(longest,count);
        }
    }

    cout << longest;

    return 0;
}