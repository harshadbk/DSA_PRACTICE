#include<iostream>
using namespace std;

int most_water_container(int arr[],int size){
    int i=0;
    int j=size-1;
    int max_water = 0;
    while (i<j)
    {
        int w = j-i;
        int h = min(arr[i],arr[j]);
        int current_max = w*h;
        max_water = max(current_max,max_water);

        if(arr[i]>arr[j]){
            j--;
        }
        else{
            i++;
        }
    }

    return max_water;
    
}

int main(){
    int arr []={4,1,3,6,9,2,4,8,7};
    int size = 9;
    cout << most_water_container(arr,size);
    return 0;
}