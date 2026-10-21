#include <iostream>
#include <list>
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

    void addedge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printadjacency(){
        for(int i=0;i<V;i++){
            cout << i << " ";
            for(int neigh:l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph e(5);

    e.addedge(0,1);
    e.addedge(1,2);
    e.addedge(1,4);
    e.addedge(2,4);
    e.addedge(2,3);
    e.addedge(4,3);

    e.printadjacency();

    return 0;
}