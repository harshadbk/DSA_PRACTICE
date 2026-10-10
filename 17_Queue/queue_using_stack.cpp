#include <iostream>
#include <stack>
using namespace std;

stack<int> a , b;
int st = -1;
int ed = -1;
int size = 0;

void push(int x){
    if(size==0){
        a.push(x);
        cout << "push into queue " << x<<endl;
        st = ed = 0;
        size++;
    }
    else {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        if(a.empty()){
            a.push(x);
            cout << "push into queue " << x <<endl;
            size++;
            ed++;
            while(!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }
    }
}

void pop(){
    if(size==0){
        cout << "Cant Pop its Underflow " << endl;
        return;
    }
    else{
        int top = a.top();
        a.pop();
        size--;
        cout << "Deleted value "<<top<<endl;
    }
}

void get_size(){
    cout << size;
}

void get_top(){
    cout << a.top();
}

void printqueue(){
    stack<int> temp = a;

    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    push(23);
    push(1);
    push(19);
    printqueue();
    pop();
    push(29);
    printqueue();
    get_size();
    get_top();
    return 0;
}