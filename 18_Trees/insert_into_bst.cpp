#include <iostream>
#include <vector>
#include <algorithm>
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

ListNode *buildtree(vector<int> &nums, int l, int r)
{
    if (l > r)
    {
        return nullptr;
    }
    int mid = l + (r - l) / 2;
    ListNode *root = new ListNode(nums[mid]);

    root->left = buildtree(nums, l, mid - 1);
    root->rit = buildtree(nums, mid + 1, r);

    return root;
}

void traverse(ListNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    traverse(root->left);
    cout << root->val << " ";
    traverse(root->rit);
}

ListNode *insertbst(ListNode *root, int val)
{
    if (root == nullptr)
    {
        return new ListNode(val);
    }

    ListNode *curr = root;

    while (true)
    {
        if (curr->val <= val)
        {
            if (curr->rit != nullptr)
            {
                curr = curr->rit;
            }
            else
            {
                curr->rit = new ListNode(val);
                break;
            }
        }
        else
        {
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new ListNode(val);
                break;
            }
        }
    }
    return root;
}

ListNode *wrongbst(ListNode *root, int val)
{
    if (root == nullptr)
    {
        return new ListNode(val);
    }

    if (root->val <= val)
    {
        root->left = wrongbst(root->left, val);
    }
    else
    {
        root->rit = wrongbst(root->rit, val);
    }

    return root;
}

bool validatebst(ListNode *root, ListNode *min, ListNode *max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (min != nullptr && root->val <= min->val)
    {
        return false;
    }
    if (max != nullptr && root->val >= max->val)
    {
        return false;
    }

    return validatebst(root->left, min, root) && validatebst(root->rit, root, max);
}

int main()
{
    vector<int> nums{3, 5, 1, 8, 7, 11, 2, 6, 90, 12};
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;
    ListNode *root = buildtree(nums, l, r);
    traverse(root);
    root = insertbst(root, 19);
    cout << endl;
    traverse(root);
    cout << endl;
    root = wrongbst(root, 9);
    traverse(root);
    cout << endl;
    cout << validatebst(root, nullptr, nullptr);
    return 0;
}