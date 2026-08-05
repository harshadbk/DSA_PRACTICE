#include <iostream>
#include <vector>
using namespace std;

int findleftmost(vector<int> &nums,int tar){
    int l = 0;
    int r = nums.size()-1;
    int leftmost = -1;

    while(l<=r){
        int mid = l + (r-l) / 2;

        if(nums[mid]==tar){
            leftmost = mid;
            r = mid-1;
        }

        else if(nums[mid] > tar){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return leftmost;
}

int findritmost(vector<int> &nums,int tar){
    int l = 0;
    int r = nums.size()-1;
    int ritmost = -1;

    while(l<=r){
        int mid = l + (r-l) / 2;

        if(nums[mid]==tar){
            ritmost = mid;
            l = mid+1;
        }

        else if(nums[mid] > tar){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ritmost;
}

int main() {
    vector<int> nums {1,2,3,3,4,4,5,6,7,8,12,14};

    int tar = 4;

    int rit = findritmost(nums,tar);
    int left = findleftmost(nums,tar);

    cout << left << "  " << rit;

    return 0;
}