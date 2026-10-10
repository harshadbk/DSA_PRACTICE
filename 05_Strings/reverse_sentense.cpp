#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main() {
    string sentense = "my name is harshad khatale .";

    reverse(sentense.begin(),sentense.end());

    int size = sentense.size();

    string ans = "";

    for(int i=0;i<size;i++){
        string word = "";
        while(i<size && sentense[i] != ' '){
            word += sentense[i];
            i++;
        }
        reverse(word.begin(),word.end());

        if(word.length() > 0){
            if(ans.size()==0){
                ans += word;
            }
            else{
            ans += " "+word;
            }
        }
    }

    cout << ans;
    cout << ans.size();
    
    return 0;
}