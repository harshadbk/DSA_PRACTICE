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
    }

    void bfs(int init, vector<bool> &visit)
    {
        visit[init] = true;
        queue<int> Q;
        Q.push(init);
        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop();
            cout << curr << " ";
            for (int v : l[curr])
            {
                if (!visit[v])
                {
                    visit[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    bool hascycle(int init,vector<bool> &visit,vector<bool> &rec){
        visit[init] = true;
        rec[init] = true;
        for(int v:l[init]){
            if(!visit[v]){
                if(hascycle(v,visit,rec)){
                    return true;
                }
            }
            else if(rec[v]){
                return true;
            }
        }
        rec[init] = false;
        return false;
    }

    bool detect(){
        vector<bool> recPath (V,false);
        vector<bool> visited (V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(hascycle(i,visited,recPath)){
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

    vector<bool> visited(5, false);
    g.bfs(0, visited);
    cout << endl ;
    cout << g.detect();

    return 0;
}