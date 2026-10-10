#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();

        unordered_map<string, int> need;
        for (string w : words) need[w]++;

        // Try all possible offsets
        for (int i = 0; i < wordCount; i++) {
            unordered_map<string, int> window;
            int left = i, right = i;
            int count = 0;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (need.count(word)) {
                    window[word]++;
                    count++;

                    // Too many of one word → shrink
                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid concatenation
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
}

int main(){
    string s = "wordgoodgoodgoodbestword";
    vector<string> str ={"word","good","best"};

    vector<int> ans=findSubstring(s,str);

    for(int num:ans){
        cout << num << " ";
    }
    
    return 0;
}