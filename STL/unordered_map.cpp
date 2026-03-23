#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["Harsh"] = 1;
    m["pratik"] = 1;
    m["Atharv"] = 5;
    m["shardul"] = 1;
    m["Shambhu"] = 1;

    if(m.find("Atharv")!=m.end()){
        cout << "Found ";
    }
    else{
        cout << "Not Found ";
    }

    // difference is it uses O(1) time complexity
    // and its dont sort the elements in map 
    return 0;
}