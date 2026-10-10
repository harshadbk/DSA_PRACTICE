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

class CList
{
public:
    node *head;
    node *tail;
    CList()
    {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        node *newnode = new node(val);
        if (head == nullptr)
        {
            head = tail = newnode;
            tail->next = head;
            return;
        }

        newnode->next = head;
        head = newnode;
        tail->next = head;
    }

    void push_back(int val)
    {
        node *newnode = new node(val);

        if (head == nullptr)
        {
            head = tail = newnode;
            tail->next = head;
            return;
        }

        if (head->next == tail)
        {
            delete head;
            head = nullptr;
            return;
        }

        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List already Empty ..\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        node *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List already Empty ..\n";
            return;
        }

        if (head->next == tail)
        {
            delete head;
            head = nullptr;
            return;
        }

        node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        node *last = temp->next;
        temp->next = head;
        delete last;
    }

    void pop_pos(int pos)
    {
        if (pos == 0)
        {
            pop_front();
            return;
        }

        int i = 0;
        node *temp = head;

        while (i != pos - 1)
        {
            temp = temp->next;
            i++;
        }

        if (temp->next == tail)
        {
            pop_back();
        }

        node *del = temp->next;
        temp->next = del->next;
        free(del);
    }

    void printdata()
    {
        node *temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "END" << endl;
    }
};

int main()
{

    CList l;
    l.push_back(8);
    l.printdata();
    l.push_front(78);
    l.pop_front();
    l.printdata();
    l.push_front(89);
    l.push_front(45);
    l.push_front(1);
    l.printdata();
    l.push_back(69);
    l.push_back(30);
    l.printdata();
    l.pop_front();
    l.printdata();
    l.pop_back();
    l.printdata();
    l.pop_pos(2);
    l.printdata();
    l.pop_pos(2);
    l.printdata();
    l.pop_pos(0);
    l.printdata();
    return 0;
}