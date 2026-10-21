#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class graph
{
    int v;
    list<int> *l;

public:
    graph(int val)
    {
        this->v = val;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs()
    {
        queue<int> Q;
        vector<bool> visited(v, false);
        Q.push(0);
        visited[0] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            cout << u << "  ";
            for (int neighbour : l[u])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    Q.push(neighbour);
                }
            }
        }
        cout << endl;
    }

    void bfs2()
    {
        queue<int> Q;
        vector<bool> visited(v, false);
        Q.push(0);

        visited[0] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            cout << u << "  ";

            for (int neigh : l[u])
            {
                if (!visited[neigh])
                {
                    visited[neigh] = true;
                    Q.push(neigh);
                }
            }
        }
    }
};

int main()
{
    graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 1);

    g.bfs();

    g.bfs2();

    return 0;
}