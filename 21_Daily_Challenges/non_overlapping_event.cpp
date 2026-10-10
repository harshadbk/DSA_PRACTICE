#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxsum(vector<vector<int>> &events){
    int n = events.size();

    sort(events.begin(), events.end());
    vector<int> maxsumfrom(n);
    maxsumfrom[n-1] = events[n-1][2];

    for(int i = n-2; i >= 0; i--){
        maxsumfrom[i] = max(maxsumfrom[i+1], events[i][2]);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        int currval = events[i][2];
        ans = max(ans, currval);

        int l = i + 1;
        int h = n - 1;
        int nextIdx = -1;
        int tar = events[i][1] + 1;

        while(l <= h){
            int mid = l + (h - l) / 2;
            if(events[mid][0] >= tar){
                nextIdx = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(nextIdx != -1){
            ans = max(ans, currval + maxsumfrom[nextIdx]);
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of events: ";
    cin >> n;

    vector<vector<int>> events(n, vector<int>(3));
    cout << "Enter events (start end value):\n";
    for(int i = 0; i < n; i++){
        cin >> events[i][0] >> events[i][1] >> events[i][2];
    }

    int result = maxsum(events);
    cout << "Maximum sum of two non-overlapping events = " << result << endl;

    return 0;
}
