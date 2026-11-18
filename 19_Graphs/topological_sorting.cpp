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
    }

    void topological_sort(int u, vector<bool> &visited, stack<int> &st)
    {
        if (visited[u])
        {
            return;
        }
        visited[u] = true;

        for (auto v : l[u])
        {
            topological_sort(v, visited, st);
        }
        st.push(u);
    }

    void topological_sort_all(vector<bool> &visited)
    {
        stack<int> st;
        for (int i = 0; i < 5; i++)
        {
            if (!visited[i])
            {
                topological_sort(i, visited, st);
            }
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
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

    vector<bool> visited(g.V, false);

    g.topological_sort_all(visited);
    return 0;
}