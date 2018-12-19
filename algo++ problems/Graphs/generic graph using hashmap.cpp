#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<class T>
class Graph
{
    unordered_map<T,list<T>> l;
public:
    Graph()
    {
    }
    void addEdge(T u,T v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for(auto data=l.begin();data!=l.end();data++)
        {
            T current=data->first;
            cout<<current<<"-> ";
            for(auto vertex=l[current].begin();vertex!=l[current].end();vertex++)
            {
                cout<<*vertex<<", ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph<int> a;
    a.addEdge(0,1);
    a.addEdge(0,3);
    a.addEdge(1,2);
    a.addEdge(3,2);
    a.addEdge(3,4);
    a.printAdjList();
    Graph<string> b;
    b.addEdge("Trump","Modi");
    b.addEdge("Modi","Yogi",false);
    b.addEdge("Putin","Modi",false);
    b.addEdge("Putin","Trump",false);
    b.addEdge("Putin","Pope",false);
    b.addEdge("Yogi","Prabhu",false);
    b.addEdge("Prabhu","Modi",false);
    b.printAdjList();
    return 0;

}
