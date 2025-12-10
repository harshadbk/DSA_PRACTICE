#include<iostream>
using namespace std;

int resize (char arr[],int size){
    int idx = 0;
    for(int i=0;i<size;i++){
        int count = 0;
        int ch = arr[i];
        while (i<size && arr[i]==ch)
        {
            count ++;
            i++;
        }

        if(count == 1){
            arr[idx++] = ch;
        }
        else{
            arr[idx++] = ch;
            string s = to_string(count);
            for(char ch:s){
                arr[idx++] = ch;
            }
        }
        i--;
        
    }
    return idx;
}

int main(){
    char arr [] = {'a','a','a','b','b','b','d'};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << resize(arr,size);
    return 0;
}