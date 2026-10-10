#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> vec = {2,5,9,7,12,17,45};

    vector<int> vec2;
    vec2.push_back(23);
    vec2.push_back(78);
    vec2.pop_back();

    cout << vec2[1];

    cout << vec.front() << endl;
    cout << vec.back() << endl;

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    vec.push_back(23);

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    vec.erase(vec.begin()+2);
    vec.erase(vec.begin()+1,vec.begin()+3);

    vec.insert(vec.begin()+1,34);
    for(int num : vec){
        cout << num << " ";
    }

    // clear and empty function

    vec.clear();

    cout << "Is our vector Empty " << vec.empty();
    
    return 0;
}