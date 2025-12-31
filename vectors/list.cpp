#include<iostream>
#include<list>
using namespace std;

//major difference is implemented as doubly linked list and we can do front and back both operation
// we cant do this lt[2] // its not dynamic array

int main(){

    list<int> lt ;
    lt.emplace_back(21);
    lt.push_back(8);
    lt.push_back(9);
    lt.push_front(12);
    lt.push_front(23);

    for(int n:lt){
        cout << n << " ";
    }

    cout << *(lt.begin());

    // we can perform all  operations of vector into list 
    
    return 0;
}