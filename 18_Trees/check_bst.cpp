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

vector<int> ans;

int prevval = -1;

bool checkbst(node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (!checkbst(root->left))
    {
        return false;
    }

    if (prevval != -1 && root->data <= prevval)
    {
        return false;
    }

    prevval = root->data;

    return checkbst(root->right);
}

int preval = INT16_MIN;
int minlen = INT16_MAX;

void mindist(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    mindist(root->left);

    if (preval != INT16_MIN)
    {
        minlen = min(minlen, abs(preval - root->data));
    }
    preval = root->data;
    mindist(root->right);
}

int sum = 0;

void ksum(node *tree, int &k)
{
    if (tree == nullptr || k <= 0)
    {
        return;
    }
    ksum(tree->left, k);
    k--;
    if (k >= 0)
    {
        sum += tree->data;
    }
    else
    {
        return;
    }

    ksum(tree->right, k);
}

bool searchbst(node *root, int &val)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    else if (root->data < val)
    {
        return searchbst(root->right, val);
    }
    else
    {
        return searchbst(root->left, val);
    }
}

int main()
{
    node *root = new node(12);
    node *root_left = new node(6);
    node *root_right = new node(33);
    node *root_left_left = new node(3);
    node *root_left_right = new node(9);

    node *root_right_left = new node(31);
    node *root_right_right = new node(39);

    root->left = root_left;
    root->right = root_right;

    root->left->left = root_left_left;
    root->left->right = root_left_right;

    root->right->left = root_right_left;
    root->right->right = root_right_right;

    cout << checkbst(root) << endl;

    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] < ans[i - 1])
        {
            cout << "0";
            return 0;
        }
    }

    cout << "1";

    mindist(root);

    cout << minlen << endl;
    int k = 8;
    ksum(root, k);

    cout << "sum is " << sum << endl;
    int val = 41;
    cout << searchbst(root, val);

    return 0;
}