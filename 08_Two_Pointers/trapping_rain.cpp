#include<iostream>
#include<vector>
using namespace std;

int traped_rain(vector<int> &heights){
    int n = heights.size();
    int left = 0;
    int right = n-1;
    int leftmax = 0,rightmax = 0;
    int water = 0;

    while (left<right)
    {
        if(heights[left]<=heights[right]){
            if(heights[left]>=leftmax){
                leftmax = heights[left];
            }
            else{
                water += leftmax - heights[left];
            }
            left++;
        }
        else {
            if(heights[right]>=rightmax){
                rightmax = heights[right];
            }
            else{
                water += rightmax - heights[right];
            }
            right--;
        }
    }
    return water;
    
}

int main(){
    vector<int> heights = {4,2,3,3,2,5};
    cout << traped_rain(heights);
    return 0;
}