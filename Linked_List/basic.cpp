#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

class Linkedlist {
private:
    node* first;
    node* last;

public:
    Linkedlist() {
        first = nullptr;
        last = nullptr;
    }

    void push_front(int val) {
        node* newnode = new node(val);
        if (first == nullptr) {
            first = last = newnode;
        } else {
            newnode->next = first;
            first = newnode;
        }
    }

    void push_back(int val) {
        node* newnode = new node(val);
        if (first == nullptr) {
            first = last = newnode;
        } else {
            last->next = newnode;
            last = newnode;
        }
    }

    // insert at index
    void insertpos(int idx, int val) {
        if (idx == 0) {
            push_front(val);
            return;
        }

        node* temp = first;
        for (int i = 0; i < idx - 1; i++) {
            if (temp == nullptr) {
                cout << "Index out of bound\n";
                return;
            }
            temp = temp->next;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;

        if (newnode->next == nullptr) {
            last = newnode;
        }
    }

    void popfront() {
        if (first == nullptr) return;

        node* temp = first;
        first = first->next;
        delete temp;

        if (first == nullptr)
            last = nullptr;
    }

    void popback() {
        if (first == nullptr) return;

        if (first == last) {
            delete first;
            first = last = nullptr;
            return;
        }

        node* temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = nullptr;
    }

    void printdata() {
        node* head = first;
        while (head != nullptr) {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "NULL"<<endl;
    }

    int search(int val){
        node *temp = first;
        int i=0;
        while(temp!=nullptr){
            if(temp->data==val){
                return i;
            }
            i++;
            temp = temp->next;
        }
        return -1;
    }
};

int main() {
    Linkedlist li;
    li.push_front(12);
    li.push_front(78);
    li.push_back(13);
    li.push_back(89);
    li.insertpos(2, 36);
    li.insertpos(3, 1);
    li.insertpos(6, 29);

    li.printdata();

    li.popfront();
    li.popback();

    li.printdata();
    cout << li.search(36)<<endl;
    li.printdata();
    return 0;
}