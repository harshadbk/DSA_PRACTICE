#include<iostream>
using namespace std;

#define MAX 100
int stack[MAX];
int top = -1;

void push(int val){

    if(stack[top]==MAX){
        cout << "Stack overflow:\n";
        return;
    }
        top++;
        stack[top] = val;
        cout << "Value push to stack "<< val << endl;
}

void pop(){
    if(top == -1){
        cout << "Stack underflow\n";
        return;
    }
    cout << "Popped element: " << stack[top] << endl;
    top--;
}

void stacktop(){
    cout << "Top Element of Stack is :"<<stack[top]<<endl;
}

void printstack(){
    cout << "Stack Elements :"<<endl;
    for(int i=top;i>=0;i--){
        cout << stack[i] << endl;
    }
}

string isempty(){
    return top==-1 ? "Empty Stack":"Not empty Stack";
}

int main(){
    push(12);
    push(68);
    pop();
    printstack();
    stacktop();
    cout << isempty();
    return 0;
}