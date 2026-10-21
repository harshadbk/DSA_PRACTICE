#include <iostream>
#include <list>
#include <queue>
#include <vector>
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

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS(int init)
    {
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(init);
        visited[init] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int n : l[u])
            {
                if (!visited[n])
                {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
        cout << endl;
    }

    void dfs(int init, vector<bool> &visited)
    {
        if (visited[init])
        {
            return;
        }

        cout << init << " ";
        visited[init] = true;

        for (int u : l[init])
        {
            dfs(u, visited);
        }
    }

    bool detectedcycle(int init, vector<bool> &visited, int parent)
    {
        visited[init] = true;

        list<int> n = l[init];

        for (int v : n)
        {
            if (!visited[v])
            {
                if (detectedcycle(v, visited, init))
                {
                    return true;
                }
            }
            else if (v != parent)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    graph g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.BFS(1);

    vector<bool> visited(4, false);
    g.dfs(1, visited);
    vector<bool> visited2(4, false);
    cout << endl;
    cout << g.detectedcycle(1, visited2, -1);

    return 0;
}