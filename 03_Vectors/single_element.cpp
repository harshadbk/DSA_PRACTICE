#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1,2,3,1,2,3,4};

    unordered_map<int,int> mp;

    for(int num:a){
        mp[num]++;
    }

    for(auto it : mp){
        if(it.second == 1){
            cout << "Single element: " << it.first;
        }
    }

    return 0;
}