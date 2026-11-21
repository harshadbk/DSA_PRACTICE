#include <iostream>
#include <vector>
#include <stack>
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
        l[v].push_back(u);
    }

    void dfs(int u, vector<bool> &vis)
    {
        if (vis[u])
        {
            return;
        }

        cout << u << " ";
        vis[u] = true;

        for (int v : l[u])
        {
            if (!vis[v])
            {
                dfs(v, vis);
            }
        }
    }

    int check_all(vector<bool> &vis){
        int count = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis);
            }
        }

        return count;
    }
};

int main()
{
    graph g(5);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(3, 2);

    g.addedge(0, 0);

    vector<bool> vis(5, false);
    cout << g.check_all(vis);

    return 0;
}