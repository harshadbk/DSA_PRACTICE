#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int idx = -1;

class Root
{
public:
    int data;
    Root *left;
    Root *right;

    Root(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Root *buildtree(vector<int> &preorder)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return nullptr;
    }
    Root *root = new Root(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root;
}

void traverse(Root *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << endl;
    traverse(node->left);
    traverse(node->right);
}

void inorder(Root *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << endl;
    inorder(node->right);
}

void postorder(Root *node)
{
    if (node == nullptr)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << endl;
}

void levelorder(Root *node)
{
    queue<Root *> q;

    q.push(node);
    q.push(NULL);

    while (q.size() > 0)
    {
        Root *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int totalheight(Root* node){
    if(node==nullptr){
        return 0;
    }

    int lefth = totalheight(node->left);
    int righth = totalheight(node->right);

    return max(lefth,righth) + 1;
}

int totalnodes(Root* node){
    if(node==nullptr){
        return 0;
    }
    int totalleft = totalnodes(node->left);
    int totalr = totalnodes(node->right);
    return totalleft + totalr + 1;
}

int totaltree(Root* node){
    if(node==nullptr){
        return 0;
    }
    
    int totalleft = totaltree(node->left);
    int totalr = totaltree(node->right);
    return totalleft + totalr + node->data;


}

int main()
{
    vector<int> preorder{1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Root *node = buildtree(preorder);
    levelorder(node);
    cout << totalheight(node) << endl;
    cout << totalnodes(node) << endl;
    cout << totaltree(node);
    return 0;
}