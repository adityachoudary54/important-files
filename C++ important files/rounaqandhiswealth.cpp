#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<class T>
class Graph
{
public:
    unordered_map<T,list<T>> l;
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
    int n,m,q,t,k[10000],f;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>k[i];
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            a.addEdge(y,x,false);
        }
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int mini=1000000000;
            cin>>f;
            for(auto vertex=a.l[f].begin();vertex!=a.l[f].end();vertex++)
            {
                if(k[*vertex-1]<mini)
                    mini=k[*vertex-1];
            }
            if(mini!=1000000000)
                cout<<mini<<endl;
            else
                cout<<-1<<endl;
        }
    }
}
