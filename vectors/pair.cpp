#include <iostream>
using namespace std;
#include <vector>

int main()
{

    pair<int, int> p = {2, 3};
    cout << p.first << endl;
    cout << p.second << endl;

    vector<pair<int, int>> pr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 0}};

    pr.push_back({12, 13});
    pr.emplace_back(23, 45);

    for (pair<int, int> p : pr)
    {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}