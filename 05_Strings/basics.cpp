#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[100];
    cout << "Enter name :";
    cin.getline(str,100,'$');
    cout << str;

    string name; // dynamically resize
    cout << "Enter name:";
    // cin >> name;
    cout << name;

    char ch []= "Mayank";
    // ch = "Raul"; // not modifiable
    int size = strlen(ch);

    // getline string

    string s ;
    getline(cin,s);
    cout << s;
    return 0;
}