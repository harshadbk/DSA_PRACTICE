#include <iostream>
#include <vector>
using namespace std;

int findleftmost(vector<int> &nums,int tar){
    int l = 1;
    int r = nums.size()-1;
    int ans = -1;
    while (l<=r)
    {
        int mid = l + (r-l) / 2;
        if(nums[mid]==tar){
            ans = mid;
            r = mid-1;
        }
        else if(nums[mid] > tar){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

int findritmost(vector<int> &nums,int tar){
    int l = 1;
    int r = nums.size()-1;
    int ans = -1;
    while (l<=r)
    {
        int mid = l + (r-l) / 2;
        if(nums[mid]==tar){
            ans = mid;
            l = mid+1;
        }
        else if(nums[mid] > tar){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums {1,2,3,4,5,6,7,8,9};
    int tar = 3;

    int leftmost = findleftmost(nums,tar);
    int ritmost = findritmost(nums,tar);
    cout << leftmost << " " << ritmost;
    return 0;
}