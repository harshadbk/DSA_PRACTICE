#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string demo = "ihavesomrsssuers";
    string subs = "ssuer";
    int count = 0;
    int m = demo.size();
    int n = subs.size();
    sort(subs.begin(),subs.end());

    for(int i=0;i<m-n+1;i++){
        string subt = demo.substr(i,n);
        sort(subt.begin(),subt.end());
        if(subt == subs){
            cout << subt << endl;
            count ++;
        }
    }
    cout << count;
    return 0;
}