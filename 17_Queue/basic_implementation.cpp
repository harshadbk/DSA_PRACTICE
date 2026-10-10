#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class queue
{
public:
    node *front = nullptr;
    node *rear = nullptr;

    void enqueue(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            front = rear = newnode;
            return;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void pop()
    {
        if (isempty())
        {
            cout << "Queue is already empty:";
            return;
        }
        else
        {
            node* todelete = front;
            front = todelete->next;
            delete todelete;
        }
    }

    int getfront()
    {
        if (isempty())
        {
            return -1;
        }
        return front->data;
    }

    bool isempty()
    {
        return front == nullptr;
    }

    void printqueue()
    {
        node *temp = front;
        while (temp != nullptr && rear != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "End\n";
    }
};

int main()
{
    queue q;
    q.enqueue(90);
    q.enqueue(12);
    q.enqueue(87);
    q.enqueue(29);

    q.printqueue();
    q.pop();
    q.printqueue();
    cout<< q.getfront();
    return 0;
}