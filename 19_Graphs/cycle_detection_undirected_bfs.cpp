#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class graph
{
    int V;
    list<int> *l;

public:
    graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
    }

    void add_edge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool checkcycle(int init, vector<bool> &visit, int par)
    {
        queue<pair<int, int>> Q;
        Q.push({init, par});
        visit[init] = true;

        while (!Q.empty())
        {
            int curr = Q.front().first;
            int par = Q.front().second;
            Q.pop();

            for (int v : l[curr])
            {
                if (!visit[v])
                {
                    visit[v] = true;
                    Q.push({v, curr});
                }

                else if (v != par)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool forallnodes()
    {
        vector<bool> visit(5, false);
        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
            {
                if (checkcycle(i, visit, -1))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 2);

    cout << g.forallnodes();

    return 0;
}