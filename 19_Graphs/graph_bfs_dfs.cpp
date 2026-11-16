#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class graph
{
    int V;
    list<int> *l;

public:
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addedge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(int u)
    {
        vector<bool> visisted(V, false);
        visisted[u] = true;

        queue<int> Q;

        Q.push(u);

        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();

            cout << v << " ";

            for (auto u : l[v])
            {
                if (!visisted[u])
                {
                    visisted[u] = true;
                    Q.push(u);
                }
            }
        }
    }

    void dfs(int u, vector<bool> &visited)
    {
        if (visited[u])
        {
            return;
        }
        cout << u << " ";

        visited[u] = true;

        for (auto v : l[u])
        {
            dfs(v, visited);
        }
    }

    bool hascycle(int init, vector<bool> &visited, int par)
    {
        visited[init] = true;
        list<int> n = l[init];

        for (int v : n)
        {
            if (!visited[v])
            {
                if (hascycle(v, visited, init))
                {
                    return true;
                }
            }
            else if (v != par)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    graph g(5);

    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 2);
    g.bfs(0);
    cout << endl;
    vector<bool> visited(5, false);
    g.dfs(0, visited);
    cout << endl;
    vector<bool> visited2(5, false);
    cout << g.hascycle(0, visited2, -1);

    return 0;
}