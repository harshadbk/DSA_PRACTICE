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

    void bfs(int init, vector<bool> &visit)
    {
        queue<int> Q;
        Q.push(init);
        visit[init] = true;

        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop();

            cout << curr << " ";

            for (auto v : l[curr])
            {
                if (!visit[v])
                {
                    visit[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    void dfs(int init, vector<bool> &visit)
    {
        if (visit[init])
        {
            return;
        }

        cout << init << " ";

        visit[init] = true;

        for (auto v : l[init])
        {

            dfs(v, visit);
        }
    }

    bool hascycle(int init, vector<bool> &visit, int parent)
    {
        visit[init] = true;
        list<int> n = l[init];

        for (int v : n)
        {
            if (!visit[v])
            {
                if (hascycle(v, visit, init))
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
    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    vector<bool> vec(5, false);
    int init = 0;
    g.bfs(init, vec);
    vector<bool> vec2(5, false);
    cout << endl;
    g.dfs(init, vec2);
    vector<bool> vec3(5, false);
    cout << endl;
    cout << g.hascycle(0, vec3, -1);

    return 0;
}