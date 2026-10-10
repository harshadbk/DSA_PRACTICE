#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

string reverse_word(string s){
    reverse(s.begin(),s.end());
    int n = s.length();
    string ans = "";
    for(int i=0;i<n;i++){
        string word = "";
        while (i<n && s[i]!=' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(),word.end());

        if(word.length()>0){
            ans += " "+word;
        }
    
    }

    return ans.substr(1);
}

int main(){
    string sentence = "   my name is harshad   khatale  ";
    cout << reverse_word(sentence);
    return 0;
}