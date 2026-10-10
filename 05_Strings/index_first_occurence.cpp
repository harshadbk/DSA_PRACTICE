#include<iostream>
using namespace std;

int indexFirst(string s,string s2){

    int n = s.size();
    int m = s2.size();

    if(n==0){
        return 0;
    }

        for(int i=0;i<=n-m;i++){
            int j=0;
            while (j<m && s[i+j]==s2[j])
            {
                j++;
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    
}

int main(){
    string s = "aakharad";
    string s2 = "har";
    cout << indexFirst(s,s2);
    return 0;
}