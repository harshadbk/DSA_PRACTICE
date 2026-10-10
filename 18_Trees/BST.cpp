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

node *createtree(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }

    if (root->data > val)
    {
        root->left = createtree(root->left, val);
    }

    else if (root->data < val)
    {
        root->right = createtree(root->right, val);
    }

    else
    {
        root->left = createtree(root->left, val);
    }
    return root;
};

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

bool search(node *root, int val)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->data == val)
    {
        return 1;
    }
    else if (root->data > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

node *deletenode(node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data > val)
    {
        root->left = deletenode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = deletenode(root->right, val);
    }

    else
    {
        // node found

        // leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // one child
        if (!root->left)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        else {
            node* temp = root;
            node* child = temp->left;
            node* parent = root;

            while(child->right != nullptr){
                parent = child;
                child = child->right;
            }

            if(root!=parent){
                parent->left = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                child->right = root->right;
                delete root;
                return child; 
            }
        }
    }

    return root;
}

int main()
{
    vector<int> nums{6, 4, 5, 1, 8, 7, 9, 11,13,12,16,19};
    node *root = nullptr;
    for (int i = 0; i < nums.size(); i++)
    {
        root = createtree(root, nums[i]);
    }
    traverse(root);
    cout << endl;
    cout << search(root, 8) << endl;
    root = deletenode(root,13);
    traverse(root);
    return 0;
}