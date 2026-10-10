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

class queue
{
    public: 
    
    int size;
    node *st;
    node *ed;

    queue()
    {
        size = 0;
        st = nullptr;
        ed = nullptr;
    }

    void enque(int x)
    {
        node *newnode = new node(x);
        if (st == nullptr)
        {
            st = ed = newnode;
            size++;
            cout << "Successfully enque element " << x << endl;
        }
        else
        {
            ed->next = newnode;
            ed = newnode;
            size++;
            cout << "Successfully enque element " << x << endl;
        }
    }

    void deque(){
        if(size == 0){
            cout << "Queue is Empty Cant deque "<<endl;
        }
        else {
            node* temp = st;
            int data = temp->data;
            st = st->next;
            delete temp;
            size--;
            cout << "Successfully deleted element " << data;
        }
    }

    void top(){
        if(size==0){
            cout << "Empty Queue Can get Top " << endl;
        }
        else {
            cout << st->data << endl;
        }
    }

    void get_size(){
        cout << size << endl;
    }
};

int main()
{
    queue q;
    q.enque(23);
    q.enque(39);
    q.top();
    q.get_size();
    q.deque();

    return 0;
}