#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int data){
        val = data;
        next = nullptr;
    }
};

class stack{
    public:
    node* top = nullptr;

    void push_element(int val){
        node* newnode = new node(val);
        if(top==nullptr){
            top = newnode;
            cout << "Inserted Element into Stack :"<<val<<endl;
            return;
        }

        newnode->next = top;
        top = newnode;
        cout << "Inserted Element into Stack :"<<val<<endl;
    }

    void pop_element(){
        if(top==nullptr){
            cout << "List is Empty "<<endl;
            return;
        }
        node* todel = top;
        cout << "safely deleted Element:"<<todel->val<<endl;
        top = top->next;
        delete todel;
        
    }

    int topval(){
        return top->val;
    }

    void printstack(){
        node*  temp = top;

        while(temp!=nullptr){
            cout << temp->val<<" "<< endl;
            temp = temp->next;
        }
    }

};

int main(){
    stack s;
    s.push_element(8);
    s.push_element(90);
    s.push_element(23);
    s.printstack();
    s.pop_element();
    s.printstack();
    cout << "Top element " <<s.topval()<<endl;
    return 0;
}