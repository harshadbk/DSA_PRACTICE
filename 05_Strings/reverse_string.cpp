#include<iostream>
#include<cstring>
using namespace std;

void reverse_string(char ch[],int size){
    int i=0;
    int j=size-1;
    while (i<=j)
    {
        swap(ch[i],ch[j]);
        i++;
        j--;
    }

    for(int i=0;i<size;i++){
        cout << ch[i] << " ";
    }
    

}

int main(){
    char ch[] = {'a','b','c','d','e','f','j'};
    int size = sizeof(ch)/sizeof(ch[0]);
    reverse_string(ch,size);
    return 0;
}