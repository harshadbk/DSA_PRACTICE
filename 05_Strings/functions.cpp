#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    string s = "Harshad";
    string ant = "bkc";

    s.append(ant);
    cout << s << endl;

    s.erase(1, 5);
    cout << s << endl;

    s.insert(1, "arsha");
    cout << s << endl;

    s.replace(1, 5, "khatale");
    cout << s << endl;

    if (s.find('k') != string::npos)
    {
        int idx = s.find('k');
        cout << idx << endl;
    }
    else
    {
        cout << "Not Found";
    }

    cout << s.front() << endl;
    cout << s.back() << endl;

    s.erase(s.begin());
    cout << s.front();
    vector<int> v{11, 21, 13, 44, 15, 26};

    vector<int> idx(v.begin(),v.end());

    int sum = accumulate(v.begin(), v.end(), 0);
    // int g = gcd(12, 18);
    cout << sum << endl;

    iota(idx.begin(), idx.end(), 0);
    
    sort(idx.begin(),idx.end(),[&](int a,int b){
        return v[a] < v[b];
    });

    for(int num:idx){
        cout << num << endl;
    }

    string bkc = "qwerty";
    string ckb = "ytrewq";

    if(ckb.compare(bkc) == -1){
        cout << "Not Found";
    }
    else{
        cout << "Found";
    }

    return 0;
}