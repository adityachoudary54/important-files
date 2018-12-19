#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;
template<class T>
class Graph
{
    unordered_map<T,list<pair<T,int>>> l;
public:
    Graph()
    {
    }
    void addEdge(T u,T v,int w,bool bidir=true)
    {
        l[u].push_back(make_pair(v,w));
        if(bidir)
        {
            l[v].push_back(make_pair(u,w));
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
                cout<<"("<<vertex->first<<","<<vertex->second<<")"<<", ";
            }
            cout<<endl;
        }
    }
    void dijkstra(T src)
    {
        set<pair<int,T>> q;//set sorts according to the first parameter
        unordered_map<T,int> dist;
        for(auto i:l)
        {
            T cur=i.first;
            dist[cur]=INT_MAX;
        }
        dist[src]=0;
        q.insert(make_pair(0,src));
        while(!q.empty())
        {
            auto cur=q.begin();
            T node=cur->second;
            int nodeDist=cur->first;
            q.erase(q.begin());
            //iterate over the neighbours of current node
            for(auto childPair:l[node])
            {
                if(nodeDist+childPair.second<dist[childPair.first])
                {
                    //in set updation not possible
                    //remove the old pair
                    T dest=childPair.first;
                    auto f=q.find(make_pair(dist[dest],dest));
                    if(f!=q.end())
                    {
                        q.erase(f);
                    }
                    //insert the new pair
                    dist[dest]=nodeDist+childPair.second;
                    q.insert(make_pair(dist[dest],dest));
                }

            }
        }
        for(auto i:dist)
        {
            cout<<"Distance of "<<src<<" from "<<i.first<<" is ->"<<i.second<<endl;
        }
    }
};
int main()
{
    Graph<int> a;
    a.addEdge(1,2,1);
    a.addEdge(1,3,4);
    a.addEdge(1,4,7);
    a.addEdge(3,2,1);
    a.addEdge(3,4,2);
    a.printAdjList();
    a.dijkstra(1);
    return 0;

}

