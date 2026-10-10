#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main() {
    vector<int> ele = {6, 8, 0, 1, 3};
    vector<int> ans(ele.size());
    stack<int> s;

    for (int i = ele.size() - 1; i >= 0; i--) {

        while (!s.empty() && ele[i] >= s.top()) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(ele[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
