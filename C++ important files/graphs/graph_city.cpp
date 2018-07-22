#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<queue>
#define hashmap unordered_map<T,vector<T>>
using namespace std;
template<typename T>
class Graph
{
    int V;
    hashmap l;
public:
    Graph(int v=0)
    {
        V=v;
    }
    void addEdge(T u,T v,bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
        else
        {
            l[v];//this inserts the key of the city where we go
        }
        V=l.size();
    }
    void printAdjList()
    {
        for(auto i=l.begin();i!=l.end();i++)
        {
            T current=i->first;
            cout<<current<<"->";
            for(int j=0;j<l[current].size();j++)
            {
                cout<<l[current][j]<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
    {
        unordered_map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T f=q.front();
            cout<<q.front()<<endl;
            q.pop();
            for(int i=0;i<l[f].size();i++)
            {
                if(!visited[l[f][i]])
                {
                    q.push(l[f][i]);
                    visited[l[f][i]]=true;
                }
            }
        }
    }
    void shortest_path(T src,T dest)
    {
        unordered_map<T,bool> visited;
        unordered_map<T,int> dist;
        for(auto it=l.begin();it!=l.end();it++)
            dist[it->first]=INT_MAX;
        unordered_map<T,T> parent;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T f=q.front();
            //cout<<q.front()<<"->";
            q.pop();
            for(int i=0;i<l[f].size();i++)
            {
                if(!visited[l[f][i]])
                {
                    dist[l[f][i]]=dist[f]+1;
                    q.push(l[f][i]);
                    visited[l[f][i]]=true;
                    parent[l[f][i]]=f;
                    if(l[f][i]==dest)
                    {
                        T temp;
                        temp=dest;
                        while(temp!=src)
                        {
                            cout<<temp<<" ";
                            temp=parent[temp];
                        }
                        cout<<src<<endl;
                        cout<<"Shortest path between "<<src<<" & "<<dest<<":"<<dist[l[f][i]]<<endl;
                        return;
                    }
                }
            }
        }
    }

    void dfsHelper(T src,unordered_map<T,bool> &visited)
    {
        visited[src]=true;
        cout<<src<<" ";
        for(auto it=l[src].begin();it!=l[src].end();it++)
        {
            if(!visited[*it]) 
            {
                dfsHelper(*it,visited);
            }
        }
    }
    void dfs()
    {
        unordered_map<T,bool> visited;
        for(auto it=l.begin();it!=l.end();it++)
        {
            if(!visited[it->first])
            {
                dfsHelper(it->first,visited);
                cout<<endl;
            }
        }
        //dfsHelper(src,visited);//ek function aur banana pada kyunki ek baar banega hr call ke sath update hoga
        //visited ko by reference pass kia gya hai REMEMBER!!!
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("Delhi","Agra");
    //g.addEdge("Delhi","Jaipur");
    g.addEdge("Jaipur","Bhopal");
    g.addEdge("Agra","Jaipur");
    g.addEdge("Mumbai","Agra");
    g.addEdge("Mumbai","Delhi");
    g.addEdge("Andaman and Nicobar","Sri lanka");
    g.printAdjList();
    g.dfs();
    /*string c1,c2;
    cin>>c1>>c2;
    g.shortest_path(c1,c2);*/
    //g.shortest_path("Jaipur","Agra");
    return 0;
}
