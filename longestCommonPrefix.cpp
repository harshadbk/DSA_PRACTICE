#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
    string longestCommonPrefix (vector<string> & strs){
      if (strs.empty()) return "";
      string prefix = strs[0];
      for(int i = 0; i<strs.size();i++){
        while(strs[i].find(prefix) != 0){
        prefix = prefix.substr(0,prefix.size()-1);
        if (prefix.empty()){
            return "";
        };
      } } 
 return prefix;
    };
};

int main(){
    Solution sol;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "\nExample 1:" << endl;
    cout << "Final Output: " << sol.longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "\nExample 2:" << endl;
    cout << "Final Output: " << sol.longestCommonPrefix(strs2) << endl;
    return 0;
}