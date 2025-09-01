#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Vector elements: ";
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    cout << "At index 1: " << v.at(1) << endl;

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.insert(v.begin() + 1, 15);
    cout << "After insertion: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    v.erase(v.begin() + 2);
    cout << "After erase: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}