#include <iostream>
#include <vector>
using namespace std;

int totaldeletion(vector<string> &strs) {
    int n = strs.size();
    int m = strs[0].size();

    vector<int> dp(m, 1);
    int best = 1;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < j; i++) {
            bool ok = true;

            for (int r = 0; r < n; r++) {
                if (strs[r][i] > strs[r][j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        best = max(best, dp[j]);
    }

    return m - best;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << "Minimum deletions required: "
         << totaldeletion(strs) << endl;

    return 0;
}
