#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
   string binarystr = bitset<16>(30).to_string();

        bool consecutivebit = false;

        for(int i=0;i<binarystr.size()-1;i++){
            if(binarystr[i]=='1' && binarystr[i+1]=='1'){
                consecutivebit = true;
            }
        }

        cout << binarystr;
    
    return 0;
}
