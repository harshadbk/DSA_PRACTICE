#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    vector<string> st {"flower","flow","flow"};
    string prefix = st[0];

    for(int i = 0; i < prefix.size(); i++) {
        for(int j = 1; j < st.size(); j++) {

            if(prefix[i] != st[j][i]) {
                cout << prefix.substr(0, i);
                return 0;
            }
        }
    }

    cout << prefix;

    return 0;
}