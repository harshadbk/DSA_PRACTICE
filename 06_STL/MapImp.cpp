#include<iostream>
#include<map>
using namespace std;

int main(){
    multimap<string,int> m;
    // m["TV"] = 12;
    // m["Freeze"] = 23;
    // m["Ac"] = 98;
    // m["Bed"] = 43;

    m.insert({"cake",78});
    m.insert({"cake",78});
    m.insert({"cake",78});
    m.insert({"cake",78});
    m.insert({"cake",78});

    m.erase(m.find("cake"));

    for(auto p:m){
        cout << p.first << "  "<<p.second << endl;
    }

    cout << "After Erase \n" ;

    for(auto p:m){
        cout << p.first << "  "<<p.second << endl;
    }
    
    return 0;
}