#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverse (vector<int> &arr,int k){
    int size = arr.size();
    k = k%size;
    int i=0;
    int j=size-1;
    while (i<j)
    {
       swap(arr[i],arr[j]);
       i++;
       j--;
    }
    i = 0;
    j=k-1;
    while (i<j)
    {
       swap(arr[i],arr[j]);
       i++;
       j--;
    }

    i = k;
    j = size-1;

     while (i<j)
    {
       swap(arr[i],arr[j]);
       i++;
       j--;
    }

    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k =3;
    reverse(arr,k);
    return 0;
}