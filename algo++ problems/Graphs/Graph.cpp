#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v)
    {
        V=v;
        //Array of linked lists
        l = new list<int>[V];
    }
    void addEdge(int u,int v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-> ";
            for(auto vertex=l[i].begin();vertex!=l[i].end();vertex++)
            {
                cout<<*vertex<<", ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph a(5);
    a.addEdge(0,1);
    a.addEdge(0,3);
    a.addEdge(1,2);
    a.addEdge(3,2);
    a.addEdge(3,4);
    a.printAdjList();
    return 0;

}
