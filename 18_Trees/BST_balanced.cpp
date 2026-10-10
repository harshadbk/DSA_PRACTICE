#include <iostream>
#include <vector>
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

int main()
{
    vector<int> nums{2, 4, 6, 7, 9, 11, 15, 17, 18};
    node *root = balanced(nums, 0, nums.size() - 1);
    traverse(root);
    return 0;
}