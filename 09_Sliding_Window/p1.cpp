#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums (256,0);
    string str = "aabcdeffa";
    int maxlen = 0;
    int left = 0;

    for(int i=0;i<str.size();i++){
        nums[str[i]]++;
        while(nums[str[i]] > 1){
            nums[str[left]]--;
            left++;
        }

        maxlen = max(maxlen,i-left+1);
    }

    cout << maxlen;
    return 0;
}