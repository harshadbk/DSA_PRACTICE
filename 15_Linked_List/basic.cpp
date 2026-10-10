#include <iostream>
#include <stack>
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

class Linkedlist
{
private:
    node *first;
    node *last;

public:
    Linkedlist()
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
        }
        else
        {
            newnode->next = first;
            first = newnode;
        }
    }

    void push_back(int val)
    {
        node *newnode = new node(val);
        if (first == nullptr)
        {
            first = last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }

    void push_back_link(int val)
    {
        node *newnode = new node(val);
        if (first == nullptr)
        {
            first = last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }

    // insert at index
    void insertpos(int idx, int val)
    {
        if (idx == 0)
        {
            push_front(val);
            return;
        }

        node *temp = first;
        for (int i = 0; i < idx - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Index out of bound\n";
                return;
            }
            temp = temp->next;
        }

        node *newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;

        if (newnode->next == nullptr)
        {
            last = newnode;
        }
    }

    void popfront()
    {
        if (first == nullptr)
            return;

        node *temp = first;
        first = first->next;
        delete temp;

        if (first == nullptr)
            last = nullptr;
    }

    void popback()
    {
        if (first == nullptr)
            return;

        if (first == last)
        {
            delete first;
            first = last = nullptr;
            return;
        }

        node *temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = nullptr;
    }

    void printdata()
    {
        node *head = first;
        while (head != nullptr)
        {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    int search(int val)
    {
        node *temp = first;
        int i = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return i;
            }
            i++;
            temp = temp->next;
        }
        return -1;
    }

    void deletefromlast(int idx)
    {
        int size = 0;
        node *temp = first;

        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }

        if (idx == size)
        {
            node *todelete = first;
            first = todelete->next;
            delete todelete;
            return;
        }

        temp = first;
        for (int i = 0; i < size - idx - 1; i++)
        {
            temp = temp->next;
        }

        node *todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
    }

    void sortbyzot()
    {
        if(first == nullptr){
            return;
        }

        node* zero = new node(0);
        node* one = new node(0);
        node* two = new node(0);

        node* currzero = zero;
        node* currone = one;
        node* currtwo = two;

        node* temp = first;

        while(temp != nullptr){
            if(temp->data == 0){
                currzero->next = temp;
                currzero= currzero->next;
            }
            else if(temp->data == 1){
                currone->next = temp;
                currone = currone->next;
            }
            else{
                currtwo->next = temp;
                currtwo = currtwo->next;
            }
            temp = temp->next;
        }

       currzero->next = (one->next) != nullptr ? one->next : two->next;
       currone->next = two->next;
       currtwo->next = nullptr;
       
       first = zero->next;

       delete zero;
       delete one;
       delete two;
    }
};

int main()
{
    Linkedlist li;
    li.push_front(1);
    li.push_front(1);
    li.push_front(2);
    li.push_front(2);
    li.push_front(1);
    li.push_front(1);
    li.push_front(1);
    li.push_front(1);
    li.push_front(2);
    li.printdata();

    li.sortbyzot();

    // li.deletefromlast(7);

    li.printdata();

    return 0;
}