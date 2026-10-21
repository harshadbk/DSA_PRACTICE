#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> child;

    Node(int x)
    {
        val = x;
    }
};

void bfs(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();

        q.pop();

        cout << curr->val << " ";

        for (Node *ch : curr->child)
        {
            q.push(ch);
        }
    }
}

void dfs(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " ";

    for (Node *ch : root->child)
    {
        dfs(ch);
    }
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    Node *n10 = new Node(10);

    // Link the nodes
    n1->child = {n2, n3, n4};

    n2->child = {n5, n6};

    n6->child = {n10};

    n4->child = {n7, n8, n9};

    bfs(n1);
    cout << endl;
    dfs(n1);

    return 0;
}