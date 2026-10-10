#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int size = 0;

int push(int x){
    if(size==0){
        q.push(x);
        size++;
        return x;
    }
    else {
        int n = q.size();
        q.push(x);

        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
        size++;
    }
}

int pop(){
    if(size==0){
        cout << "Queue Is empty Cant deleted \n" << endl;
    }
    int val = q.front();
    q.pop();
    size--;
    return val;
}

int top(){
    return q.front();
}

void printstack(){
    queue<int> temp = q;

    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
}


int main() {
    push(23);
    push(12);
    push(1);
    push(19);
    printstack();

    pop();
    printstack();
    cout << top();
    
    return 0;
}