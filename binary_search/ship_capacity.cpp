#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool calculate_wet(vector<int> &nums,int maxwt,int days){
    int currwet = 0;
    int day = 1;
    for(int num:nums){

        if(num > maxwt){
            return false;
        }

        if(currwet+num <= maxwt){
            currwet += num;
        }
        else {
            day++;
            currwet = num;
        }
    }
    return day <= days;
}

int main() {
    vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int st = *max_element(nums.begin(),nums.end());
    int ed = 0;

    for(int num:nums){
        ed += num;
    }

    int ans = ed;

    while(st<=ed){
        int mid = st + (ed-st) / 2;

        bool allowedwet = calculate_wet(nums,mid,days);

        if(allowedwet){
            ans = mid;
            ed = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }

    cout << ans;

    return 0;
}