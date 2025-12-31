#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int> dq;
    dq.push_back(67);
    dq.emplace_back(89);

    cout << dq[1];
    return 0;
}