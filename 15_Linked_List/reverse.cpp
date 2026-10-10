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

class ll
{
public:
    node *first = nullptr;
    node *last = nullptr;

    void add_first(int val)
    {
        node *newnode = new node(val);

        if ((first == nullptr) && (last == nullptr))
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            newnode->next = first;
            first = newnode;
        }
    }

    void add_last(int val)
    {
        node *newnode = new node(val);

        if ((first == nullptr) && (last == nullptr))
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }

    void printlist()
    {
        node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverse()
    {
        node *curr = first;
        node *prev = nullptr;

        while (curr != nullptr)
        {
            node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        first = prev;
    }

    void reordered()
    {
        node *slow = first;
        node *fast = first;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        node *l2 = slow->next;
        slow->next = nullptr;

        node *prev = nullptr;
        node *curr = l2;

        while (curr != nullptr)
        {
            node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        node *l1 = first;
        l2 = prev;

        while (l2 != nullptr)
        {
            node *next1 = l1->next;
            node *next2 = l2->next;

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};

int main()
{
    ll l1;
    l1.add_first(23);
    l1.add_first(45);
    l1.add_last(11);
    l1.add_last(90);
    l1.add_first(33);
    l1.add_first(44);
    l1.add_first(21);
    l1.add_first(49);
    l1.add_first(27);
    l1.add_first(43);
    l1.printlist();
    l1.reverse();
    cout << endl;
    l1.printlist();
    l1.reordered();
    cout << endl;
    l1.printlist();

    return 0;
}