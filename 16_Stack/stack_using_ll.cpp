#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class list
{
public:
    int size;
    node *top;

    list(){
        top = nullptr;
        size = 0;
    }

    void push(int x)
    {
        node *newnode = new node(x);
        if (top == nullptr)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
            size++;
            cout << "Successfully push element " << x << endl;
        }
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "List Is Empty \n";
            return 0;
        }
        else
        {
            int val = top->data;
            node *temp = top;
            top = top->next;
            delete temp;
            size--;
            return val;
        }
    }

    int top(){
        if(top==nullptr){
            cout << "List Empty \n";
            return 0;
        }
        else {
            return top->data;
        }
    }

    int size(){
        return size;
    }

    void printstack()
    {
        node *temp = top;
        if (temp == nullptr)
        {
            cout << "List Is Empty \n";
            return;
        }

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{

    list l;

    l.push(12);
    l.push(23);
    l.push(89);

    cout << l.pop() << endl;

    l.printstack();

    return 0;
}