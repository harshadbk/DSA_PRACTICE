#include<iostream>
using namespace std;

int main(){
    int arr [] ={1,1,1,1,1,1};
    int size = 6;
    int sum = 0;
    int product = 1;
    for(int i=0;i<size;i++){
       sum += arr[i];
       product *= arr[i];
    }
    cout << "Sum is:"<<sum;
    cout << "Product is:"<<product;

    return 0;
}