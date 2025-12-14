#include <iostream>
using namespace std;

void printnum(int n){
   if(n==1){
    cout << "1 "<<endl;
    return;
   }
   cout << n << " ";
   printnum(n-1);
}

int main(){
    printnum(4);
    return 0;
}
