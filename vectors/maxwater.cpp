#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> pills {1,1};
    int i=0;
    int maxwater = INT16_MIN;
    int j = pills.size()-1;
    while(i<j){
        int h = j-i;
        int w = min(pills[i],pills[j]);
        int currwater = h*w;

        maxwater = max(maxwater,currwater);

        if(pills[i] > pills[j]){
            j--;
        }
        else{
            i++;
        }
    }

    cout << maxwater;
    
    return 0;
}