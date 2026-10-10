#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(8);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout << *(s.lower_bound(6))<<endl;
    cout << *(s.upper_bound(4));
    return 0;
}