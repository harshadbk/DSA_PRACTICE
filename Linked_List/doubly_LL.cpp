#include <iostream>
using namespace std;

class node
{
public:
    int no;
    node *next;
    node *prev;
    node(int val)
    {
        no = val;
        next = nullptr;
        prev = nullptr;
    }
};

class List
{
public:
    node *first;
    node *last;
    List()
    {
        first = nullptr;
        last = nullptr;
    }
    void push_front(int val)
    {
        node *newnode = new node(val);
        if (first == nullptr)
        {
            first = last = newnode;
            return;
        }

        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }

    void push_back(int val)
    {
        node *newnode = new node(val);

        if (last == nullptr)
        {
            last = first = newnode;
            return;
        }

        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }

    void insertbetween(int val, int pos)
    {
        node *newnode = new node(val);
        if (pos == 0)
        {
            if (first == nullptr)
            {
                first = last = newnode;
                return;
            }
            else
            {
                newnode->next = first;
                first->prev = newnode;
                first = newnode;
                return;
            }
        }

        int i = 0;
        node *temp = first;
        while (temp != nullptr && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr)
        {
            cout << "Invalid Position:\n";
            delete newnode;
            return;
        }

        if (temp->next == nullptr)
        {
            temp->next = newnode;
            newnode->prev = temp;
            last = newnode;
        }
        else
        {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }

    void pop_front()
    {
        if (first == nullptr)
        {
            cout << "List already empty";
            return;
        }

        node *temp = first;
        first = first->next;

        if (first != nullptr)
        {
            first->prev = nullptr;
        }
        else
        {
            // list became empty
            last = nullptr;
        }

        delete temp;
    }

    void pop_back()
    {
        if (first == nullptr)
        {
            cout << "List already empty:";
            return;
        }

        node *temp = first;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        temp->prev = temp->prev->prev;
        last = temp->prev;
        free(temp);
    }

    void pop_pos(int pos){
        if(pos==0){
            if(first==nullptr){
                cout << "List is already Empty:";
                return;
            }
            node* temp = first;
            first = first->next;
            first->prev = nullptr;
            temp->next = nullptr;
            free(temp);
        }

        
    }

    void printlist()
    {
        node *ptr = first;
        while (ptr != nullptr)
        {
            cout << ptr->no << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List l;
    l.push_front(78);
    l.push_front(11);
    l.push_front(23);
    l.push_back(45);
    l.insertbetween(29, 0);
    l.insertbetween(9, 7);
    l.insertbetween(56, 2);
    l.insertbetween(71, 6);
    l.printlist();
    l.pop_front();
    l.printlist();
    l.pop_back();
    l.printlist();
    l.pop_pos(0);
    l.printlist();
    return 0;
}