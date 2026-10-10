#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

    int arr[] = {2,6,5,3,9,12,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_idx = max_element(arr,arr+n)-arr;

    cout << max_idx;    
    return 0;
}