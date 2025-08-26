#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long reverse = 0;
        int original = x;

        while (x > 0) {
            int digit = x % 10;          
            reverse = reverse * 10 + digit; 
            x = x / 10;                 
        }

        return reverse == original;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome(121) << endl;
    cout << sol.isPalindrome(-121) << endl;
    cout << sol.isPalindrome(10) << endl;    
    return 0;
}
