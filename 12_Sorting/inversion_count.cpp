#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int ed)
{
    vector<int> temp;
    int incount = 0;
    int i=st;
    int j=mid+1;
    while (i<=mid && j<=ed)
    {
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            incount +=(mid-i+1);
        }
    }
    while (i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=ed)
    {
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int i=0;i<temp.size();i++){
        arr[i+st] = temp[i];
    }

    return incount;
}

int inverscount(vector<int> &arr, int st, int ed)
{
    if (st < ed)
    {
        int mid = st + (ed - st) / 2;
        int leftc = inverscount(arr, st, mid);
        int rcount = inverscount(arr, mid + 1, ed);
        return merge(arr, st, mid, ed)+leftc+rcount;
    }
    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5,2,7};
    cout << inverscount(arr, 0, arr.size() - 1);
    return 0;
}