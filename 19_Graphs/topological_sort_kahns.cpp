#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;

class graph
{
public:
    int V;
    list<int> *l;
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addedge(int u, int v)
    {
        l[u].push_back(v);
    }

    void calcindegree()
    {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int u : l[i])
            {
                indegree[u]++;
            }
        }

        for (int i = 0; i < indegree.size(); i++)
        {
            cout << indegree[i] << " ";
        }

        cout << endl;

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> res;

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int u : l[curr])
            {
                indegree[u]--;
                if (indegree[u] == 0)
                {
                    q.push(u);
                }
            }
        }

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
};

int main()
{
    graph g(5);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(3, 2);
    g.addedge(3, 4);
    g.addedge(0, 4);

    g.calcindegree();

    return 0;
}