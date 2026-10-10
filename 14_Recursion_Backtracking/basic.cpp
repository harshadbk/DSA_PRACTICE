#include <iostream>
using namespace std;

void printnum(int n,int i){
   if(i==n){
    cout << n <<endl;
    return;
   }
   cout << i;
   i++;
   printnum(n,i);
}

int main(){
    printnum(4,0);
    return 0;
}
