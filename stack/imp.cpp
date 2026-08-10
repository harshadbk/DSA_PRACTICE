#include <iostream>
#include <vector>
using namespace std;

class stack {

    public:

    int arr [5];
    int top = -1;

    int push(int x){
        if(top >= 4){
            cout << "Stack Overflow Cant add element";
            return 0;
        }
        top++;
        arr[top] = x;
    }

    int pop(){
        if(top==-1){
            cout << "Stack Underflow Cant remove element";
            return 0;
        }
        top--;
    }

    int get_top(){
        if(top != -1){
            return arr[top];
        }
    }

    int size(){
        return top + 1;
    }
};

int main() {

    stack t;

    t.push(1);
    t.push(2);
    t.push(3);
    t.push(4);
    t.push(5);
    t.push(6);

    cout << t.get_top();
    
    return 0;
}