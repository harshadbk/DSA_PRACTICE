#include <iostream>
#include <utility>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *left;
    ListNode *rit;

    ListNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->rit = nullptr;
    }
};

void traverse(ListNode *root)
{
    if (root == nullptr)
        return;

    traverse(root->left);
    cout << root->val << " ";
    traverse(root->rit);
}

ListNode *pre = nullptr;
ListNode *first = nullptr;
ListNode *second = nullptr;

void swapnode(ListNode *root)
{
    if (root == nullptr)
        return;

    swapnode(root->left);

    if (pre != nullptr && pre->val > root->val)
    {
        if (first == nullptr)
            first = pre;

        second = root;
    }

    pre = root;

    swapnode(root->rit);
}

int main()
{
    ListNode *root = new ListNode(10);
    ListNode *sec = new ListNode(5);
    ListNode *t = new ListNode(1);
    ListNode *f = new ListNode(12);
    ListNode *ft = new ListNode(11);
    ListNode *si = new ListNode(8);
    ListNode *sv = new ListNode(18);

    root->left = sec;
    root->left->left = t;
    root->left->rit = f;
    root->rit = si;
    root->rit->left = ft;
    root->rit->rit = sv;

    cout << "Before: ";
    traverse(root);

    swapnode(root);

    if (first != nullptr && second != nullptr)
        swap(first->val, second->val);

    cout << "\nAfter:  ";
    traverse(root);

    return 0;
}