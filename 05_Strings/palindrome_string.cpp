#include<iostream>
using namespace std;

bool isalphanumeric(char ch){
    ch = tolower(ch);
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) {
        return true;
    }
    return false;
}

bool ispalindrome(char st[],int size){
    int i=0;
    int j=size-1;
    while (i<j)
    {
       if(!isalphanumeric(st[i])){
            i++;
            continue;
       }
       if(!isalphanumeric(st[j])){
            j--;
            continue;
       }

       if(tolower(st[i])!=tolower(st[j])){
        return false;
       }
       i++;
       j--;
    }
    return true;
    
}

int main(){
    char st [] = {"A man, a plan, a canal: Panama"};
    int size = sizeof(st)/sizeof(st[0]);
    cout << ispalindrome(st,size);
    return 0;
}