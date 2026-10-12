#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *balanced(vector<int> &nums, int st, int ed)
{
    if (st > ed)
    {
        return nullptr;
    }
    int mid = st + (ed - st) / 2;

    node *root = new node(nums[mid]);

    root->left = balanced(nums, st, mid - 1);
    root->right = balanced(nums, mid + 1, ed);

    return root;
}

void traverse(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    traverse(root->left);
    cout << root->data << "  ";
    traverse(root->right);
}

node *insertbst(node *root, int &val)
{
    if (root == nullptr)
    {
        return new node(val);
    }

    if (root->data > val)
    {
        root->left = insertbst(root->left, val);
    }
    else
    {
        root->right = insertbst(root->right, val);
    }

    return root;
}

node *insertbstloop(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }

    node *temp = root;

    while (true)
    {
        if (temp->data > val)
        {
            if (temp->left != nullptr)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new node(val);
                break;
            }
        }
        else
        {
            if (temp->right != nullptr)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new node(val);
                break;
            }
        }
    }

    return root;
}

int mindist = INT16_MAX;
int previ = -1;

void mindiff(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    mindiff(root->left);

    if (root != nullptr && previ != -1)
    {
        mindist = min(mindist, abs(root->data - previ));
    }

    previ = root->data;
    mindiff(root->right);
}

int main()
{
    vector<int> nums{2, 4, 6, 7, 9, 11, 15, 17, 18};
    node *root = balanced(nums, 0, nums.size() - 1);
    traverse(root);
    cout << "\n After Insertion " << endl;
    int val = 22;
    insertbst(root, val);
    traverse(root);
    cout << "\n After Insertion by loop " << endl;
    int val2 = 14;
    insertbstloop(root, val2);
    traverse(root);
    cout << "\n Minimum Distance in tree is " << endl;
    mindiff(root);
    cout << mindist;
    return 0;
}