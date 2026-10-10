#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isalphanumeric(char ch){
    ch = tolower(ch);
    if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')){
        return true;
    }
    return false;
}

int main() {

    string abc = "A man, a plan, a canal: Panama";

    int i=0;
    int j = abc.size();

    while(i<j){
        if(!isalphanumeric(abc[i])){
            i++;
            continue;
        }
        if(!isalphanumeric(abc[j])){
            j--;
            continue;
        }
        if(tolower(abc[i]) != tolower(abc[j])){
            cout << "Not";
            return 0;
        }
        i++;
        j--;
    }

    cout << "Yes";
    
    return 0;
}