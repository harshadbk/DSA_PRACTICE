#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> vec = {2,5,6,8,9,11,23,42,55,61};

    cout << *(vec.begin()) << endl;

    cout << *(vec.end()-1) << endl;

    vector<int>::reverse_iterator it;

    for(auto it=vec.begin();it!=vec.end();it++){
        cout << *(it) << endl;
    }

    for(auto it=vec.rbegin();it!=vec.rend();it++){
        cout << *(it) << endl;
    }
    
    return 0;
}