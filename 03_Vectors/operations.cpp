#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> nums {1,2,3,4,5,6,6,7,7,8};
    vector<int> num2 {2,4,6,8,10,12,14,16,16,12};
    cout << nums.size() << endl;
    cout << nums.empty() << endl;
    cout << nums.front() << endl;
    cout << nums.back() << endl;
    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());

    auto it = max_element(nums.begin(),nums.end());

    // if(it != nums.end()){
        cout << *it << endl;
    // }

    int sum = accumulate(nums.begin(),nums.end(),0);
    cout << sum;

    auto it2 = find(nums.begin(),nums.end(),3);

    if(it2 != nums.end()){
        cout << "Found" << *it2;
    }
    else {
        cout << "Not found";
    }

    int ct = count(nums.begin(),nums.end(),7);
    cout << ct;

    nums.erase(nums.begin());

    for(int num : nums){
        cout << num << endl;
    }

    cout << endl;

    nums.swap(num2);

      for(int num : nums){
        cout << num << endl;
    }

    cout << nums.at(4) << endl;
    cout << endl;

    nums.erase(nums.begin(),nums.begin()+4);

    for(int num : nums){
        cout << num << endl;
    }

    cout << endl;
    nums.erase(nums.begin()+3);

    for(int num : nums){
        cout << num << endl;
    }

    cout << endl;

    auto lb = lower_bound(nums.begin(),nums.end(),16);
    auto ub = upper_bound(nums.begin(),nums.end(),16);

    int idx = lb - nums.begin();
    cout << idx;

    int count = ub - lb;
    cout << count;

    return 0;
}