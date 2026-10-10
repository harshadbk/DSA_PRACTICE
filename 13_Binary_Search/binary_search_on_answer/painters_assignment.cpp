#include <iostream>
using namespace std;

bool is_valid(int arr[],int m,int n,int maximum_allocation){
    int painter = 1;
    int time = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>maximum_allocation){
            return false;
        }
        if(time+arr[i]<=maximum_allocation){
            time += arr[i];
        }
        else{
            painter ++;
            time = arr[i];
        }
    }
    return painter > m ? false : true;
}

int allocate_painter(int arr[], int m , int n)
{
    if(m>n){
        return -1;
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int ans = -1;
    int st = 0;
    int ed = sum;
    while (st<=ed)
    {
        int mid = st+(ed-st)/2;
        if(is_valid(arr,m,n,mid)){
            ans = mid;
            ed = mid-1;
        }
        else{
            st = mid+1;
        }

    }
    return ans;
    
}

int main()
{
    int arr[] = {10,30,40,60,20,40};
    int m = 2;
    int n = 6;
    cout << allocate_painter(arr,m,n);

    return 0;
}